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
 * @file AmlipId.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen and refactored by a proto-intelligent try-hard human.
 */

#ifndef AMLIP__SRC_CPP_AMLIPTYPES_AMLIPID_HPP
#define AMLIP__SRC_CPP_AMLIPTYPES_AMLIPID_HPP

#include <array>
#include <limits>

#include <amlip_node/types/InterfaceDataType.hpp>

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


namespace eprosima {
namespace amlip {
namespace types {

constexpr const size_t ID_SIZE = 32;

/*!
 * @brief This class represents the structure AmlipId defined by the user in the IDL file.
 * @ingroup AMLIP
 */
class AmlipId : public InterfaceDataType
{
public:

    /*!
     * @brief Default constructor.
     */
    AmlipId();

    /*!
     * @brief Default destructor.
     */
    ~AmlipId();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object AmlipId that will be copied.
     */
    AmlipId(
            const AmlipId& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object AmlipId that will be copied.
     */
    AmlipId(
            AmlipId&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object AmlipId that will be copied.
     */
    AmlipId& operator =(
            const AmlipId& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object AmlipId that will be copied.
     */
    AmlipId& operator =(
            AmlipId&& x);

    /*!
     * @brief Comparison operator.
     * @param x AmlipId object to compare.
     */
    bool operator ==(
            const AmlipId& x) const;

    /*!
     * @brief Comparison operator.
     * @param x AmlipId object to compare.
     */
    bool operator !=(
            const AmlipId& x) const;

    /*!
     * @brief This function copies the value in member id
     * @param _id New value to be copied in member id
     */
    void id(
            const std::array<char, ID_SIZE>& _id);

    /*!
     * @brief This function returns a constant reference to member id
     * @return Constant reference to member id
     */
    const std::array<char, ID_SIZE>& id() const;

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    static size_t getMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    static size_t getCdrSerializedSize(
            const AmlipId& data,
            size_t current_alignment = 0);


    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void serialize(
            eprosima::fastcdr::Cdr& cdr) const override;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void deserialize(
            eprosima::fastcdr::Cdr& cdr) override;



    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    static size_t getKeyMaxCdrSerializedSize(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    static bool isKeyDefined();

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void serializeKey(
            eprosima::fastcdr::Cdr& cdr) const override;

    static bool is_bounded();

    static bool is_plain();

    static bool construct_sample(
            void* memory);

    static const char* type_name();

    bool is_defined() const noexcept;

    static AmlipId new_unique_id();

    static AmlipId undefined_id();

protected:

    std::array<char, ID_SIZE> id_;

    static const AmlipId UNDEFINED_ID_;
};

//! \c AmlipId to stream serializator
std::ostream& operator <<(
        std::ostream& os,
        const AmlipId& id);

} /* namespace types */
} /* namespace amlip */
} /* namespace eprosima */

#endif // AMLIP__SRC_CPP_AMLIPTYPES_AMLIPID_HPP