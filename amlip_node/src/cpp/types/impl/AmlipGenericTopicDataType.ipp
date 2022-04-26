// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file AmlipGenericTopicDataType.ipp
 */

#ifndef AMLIP__SRC_CPP_AMLIPTYPES_IMPL_AMLIPGENERICTOPICDATATYPE_IPP
#define AMLIP__SRC_CPP_AMLIPTYPES_IMPL_AMLIPGENERICTOPICDATATYPE_IPP

#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include <types/AmlipGenericTopicDataType.hpp>

namespace eprosima {
namespace amlip {
namespace types {

using SerializedPayload_t = eprosima::fastrtps::rtps::SerializedPayload_t;
using InstanceHandle_t = eprosima::fastrtps::rtps::InstanceHandle_t;

template <class T>
AmlipGenericTopicDataType<T>::AmlipGenericTopicDataType()
{
    setName(T::type_name());
    auto type_size = T::getMaxCdrSerializedSize();
    type_size += eprosima::fastcdr::Cdr::alignment(type_size, 4); /* possible submessage alignment */
    m_typeSize = static_cast<uint32_t>(type_size) + 4; /*encapsulation*/
    m_isGetKeyDefined = T::isKeyDefined();
    size_t keyLength = T::getKeyMaxCdrSerializedSize() > 16 ?
            T::getKeyMaxCdrSerializedSize() : 16;
    m_keyBuffer = reinterpret_cast<unsigned char*>(malloc(keyLength));
    memset(m_keyBuffer, 0, keyLength);
}

template <class T>
AmlipGenericTopicDataType<T>::~AmlipGenericTopicDataType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

template <class T>
bool AmlipGenericTopicDataType<T>::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    T* p_type = static_cast<T*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->max_size);
    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        // Serialize the object.
        p_type->serialize(ser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    // Get the serialized length
    payload->length = static_cast<uint32_t>(ser.getSerializedDataLength());
    return true;
}

template <class T>
bool AmlipGenericTopicDataType<T>::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    //Convert DATA to pointer of your type
    T* p_type = static_cast<T*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(payload->data), payload->length);

    // Object that deserializes the data.
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN, eprosima::fastcdr::Cdr::DDS_CDR);

    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        // Deserialize the object.
        p_type->deserialize(deser);
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

template <class T>
std::function<uint32_t()> AmlipGenericTopicDataType<T>::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return static_cast<uint32_t>(T::getCdrSerializedSize(*static_cast<T*>(data))) +
                      4u /*encapsulation*/;
           };
}

template <class T>
void* AmlipGenericTopicDataType<T>::createData()
{
    return reinterpret_cast<void*>(new T());
}

template <class T>
void AmlipGenericTopicDataType<T>::deleteData(
        void* data)
{
    delete(reinterpret_cast<T*>(data));
}

template <class T>
bool AmlipGenericTopicDataType<T>::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }

    T* p_type = static_cast<T*>(data);

    // Object that manages the raw buffer.
    eprosima::fastcdr::FastBuffer fastbuffer(reinterpret_cast<char*>(m_keyBuffer),
            T::getKeyMaxCdrSerializedSize());

    // Object that serializes the data.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);
    p_type->serializeKey(ser);
    if (force_md5 || T::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, static_cast<unsigned int>(ser.getSerializedDataLength()));
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

} /* namespace types */
} /* namespace amlip */
} /* namespace eprosima */

#endif // AMLIP__SRC_CPP_AMLIPTYPES_IMPL_AMLIPGENERICTOPICDATATYPE_IPP
