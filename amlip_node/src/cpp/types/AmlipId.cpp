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
 * @file amlip.cpp
 * This source file contains the definition of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen and refactored by a proto-intelligent try-hard human.
 */

#ifdef _WINID_SIZE
// Remove linker warning LNK4221 on Visual Studio
namespace {
char dummy;
}  // namespace
#endif  // _WINID_SIZE

#include <fastcdr/Cdr.h>

#include <fastcdr/exceptions/BadParamException.h>
using namespace eprosima::fastcdr::exception;

#include <utility>
#include <random>

#include <network/topics.hpp>
#include <amlip_node/types/AmlipId.hpp>

namespace eprosima {
namespace amlip {
namespace types {

const AmlipId AmlipId::UNDEFINED_ID_= AmlipId();

AmlipId::AmlipId()
{
    memset(&id_, 0, (ID_SIZE) * 1);
}

AmlipId::~AmlipId()
{
}

AmlipId::AmlipId(
        const AmlipId& x)
{
    id_ = x.id_;
}

AmlipId::AmlipId(
        AmlipId&& x)
{
    id_ = std::move(x.id_);
}

AmlipId& AmlipId::operator =(
        const AmlipId& x)
{
    id_ = x.id_;
    return *this;
}

AmlipId& AmlipId::operator =(
        AmlipId&& x)
{
    id_ = std::move(x.id_);
    return *this;
}

bool AmlipId::operator ==(
        const AmlipId& x) const
{
    return (id_ == x.id_);
}

bool AmlipId::operator !=(
        const AmlipId& x) const
{
    return !(*this == x);
}

size_t AmlipId::getMaxCdrSerializedSize(
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;

    current_alignment += ((ID_SIZE) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);

    return current_alignment - initial_alignment;
}

size_t AmlipId::getCdrSerializedSize(
        const AmlipId&,
        size_t current_alignment)
{
    size_t initial_alignment = current_alignment;

    current_alignment += ((ID_SIZE) * 1) + eprosima::fastcdr::Cdr::alignment(current_alignment, 1);
    return current_alignment - initial_alignment;
}

void AmlipId::serialize(
        eprosima::fastcdr::Cdr& scdr) const
{
    scdr << id_;
}

void AmlipId::deserialize(
        eprosima::fastcdr::Cdr& dcdr)
{
    dcdr >> id_;
}

/*!
 * @brief This function copies the value in member id
 * @param _id New value to be copied in member id
 */
void AmlipId::id(
        const std::array<char, ID_SIZE>& _id)
{
    id_ = _id;
}

/*!
 * @brief This function returns a constant reference to member id
 * @return Constant reference to member id
 */
const std::array<char, ID_SIZE>& AmlipId::id() const
{
    return id_;
}

size_t AmlipId::getKeyMaxCdrSerializedSize(
        size_t current_alignment)
{
    return current_alignment;
}

bool AmlipId::isKeyDefined()
{
    return false;
}

void AmlipId::serializeKey(
        eprosima::fastcdr::Cdr&) const
{
}

const char* AmlipId::type_name()
{
    return network::AMLIPID_TOPIC_DATATYPE;
}

bool AmlipId::is_bounded()
{
    return true;
}

bool AmlipId::is_plain()
{
    return true;
}

bool AmlipId::construct_sample(
        void* memory)
{
    return new (memory) AmlipId();
}

bool AmlipId::is_defined() const noexcept
{
    return (*this) == UNDEFINED_ID_;
}

AmlipId AmlipId::new_unique_id()
{
    // initialize the random number generator
    srand (time(NULL));

    std::array<char, ID_SIZE> id_array;

    for (int i=0; i<ID_SIZE; i++)
    {
        // generate a random char between 'a' and 'z'
        char c = 'a' + static_cast<char>(rand() % 26);
        id_array[i] = c;
    }

    AmlipId new_id;
    new_id.id(id_array);

    return new_id;
}

AmlipId AmlipId::undefined_id()
{
    return UNDEFINED_ID_;
}

std::ostream& operator <<(
        std::ostream& os,
        const AmlipId& id)
{
    os << "ID{";
    for (char v : id.id())
    {
        os << v;
    }
    os << "}";
    return os;
}

} /* namespace types */
} /* namespace amlip */
} /* namespace eprosima */
