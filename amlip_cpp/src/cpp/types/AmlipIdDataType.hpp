// Copyright 2022 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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
 * @file AmlipIdDataType.hpp
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool fastddsgen and refactored by a try-hard human.
 */

#ifndef AMLIP__SRC_CPP_AMLIPCPP_AMLIPIDDATATYPE_HPP
#define AMLIP__SRC_CPP_AMLIPCPP_AMLIPIDDATATYPE_HPP

#include <array>
#include <limits>
#include <ostream>
#include <string>

#include <types/InterfaceDataType.hpp>

namespace eprosima {
namespace fastcdr {
class Cdr;
} // namespace fastcdr
} // namespace eprosima


namespace eprosima {
namespace amlip {
namespace types {

constexpr const uint32_t NAME_SIZE = 12; // assert(!(8*NAME_SIZE % 6))
constexpr const uint32_t RAND_SIZE = 1;

/*!
 * @brief This class represents the structure AmlipIdDataType defined by the user in the IDL file.
 * @ingroup AMLIP
 */
class AmlipIdDataType : public InterfaceDataType
{
public:

    /*!
     * @brief Default constructor.
     */
    AmlipIdDataType();

    /*!
     * @brief Constructor with name.
     */
    AmlipIdDataType(const std::string& name);

    /*!
     * @brief Constructor with name given in char*.
     */
    AmlipIdDataType(const char* name);

    AmlipIdDataType(
        std::array<uint8_t, NAME_SIZE>& name,
        std::array<uint8_t, RAND_SIZE>& rand_id);

    /*!
     * @brief Constructor given fields.
     *
     * The parameters must be moved, as they will taken as part of the new object.
     */
    AmlipIdDataType(
        std::array<uint8_t, NAME_SIZE>&& name,
        std::array<uint8_t, RAND_SIZE>&& rand_id);

    /*!
     * @brief Default destructor.
     */
    ~AmlipIdDataType();

    /*!
     * @brief Copy constructor.
     * @param x Reference to the object AmlipIdDataType that will be copied.
     */
    AmlipIdDataType(
            const AmlipIdDataType& x);

    /*!
     * @brief Move constructor.
     * @param x Reference to the object AmlipIdDataType that will be copied.
     */
    AmlipIdDataType(
            AmlipIdDataType&& x);

    /*!
     * @brief Copy assignment.
     * @param x Reference to the object AmlipIdDataType that will be copied.
     */
    AmlipIdDataType& operator =(
            const AmlipIdDataType& x);

    /*!
     * @brief Move assignment.
     * @param x Reference to the object AmlipIdDataType that will be copied.
     */
    AmlipIdDataType& operator =(
            AmlipIdDataType&& x);

    /*!
     * @brief Comparison operator.
     * @param x AmlipIdDataType object to compare.
     */
    bool operator ==(
            const AmlipIdDataType& x) const;

    /*!
     * @brief Comparison operator.
     * @param x AmlipIdDataType object to compare.
     */
    bool operator !=(
            const AmlipIdDataType& x) const;

    /*!
     * @brief This function copies the value in member id
     * @param _id New value to be copied in member id
     */
    std::string name() const;

    void name(const std::array<uint8_t, NAME_SIZE>& name);

    /*!
     * @brief This function copies the value in member id
     * @param _id New value to be copied in member id
     */
    const std::array<uint8_t, NAME_SIZE>& base64_name() const;

    /*!
     * @brief This function copies the value in member id
     * @param _id New value to be copied in member id
     */
    const std::array<uint8_t, RAND_SIZE>& id() const;

    void id(const std::array<uint8_t, RAND_SIZE>& id);

    static const char* type_name();

    bool is_defined() const noexcept;

    static AmlipIdDataType new_unique_id();

    static AmlipIdDataType new_unique_id(const std::string& name);

    static AmlipIdDataType new_unique_id(const char* name);

    static AmlipIdDataType undefined_id();

    static std::array<uint8_t, NAME_SIZE> str_name_to_array(const std::string& name);

    static std::array<uint8_t, NAME_SIZE> random_name();

    static std::array<uint8_t, RAND_SIZE> random_id();

    /////
    // InterfaceDataType methods

    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void serialize(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void deserialize(
            eprosima::fastcdr::Cdr& cdr);

    /*!
     * @brief This function serializes the key members of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void serialize_key(
            eprosima::fastcdr::Cdr& cdr) const;

    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    static size_t get_max_cdr_serialize_size(
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the serialized size of a data depending on the buffer alignment.
     * @param data Data which is calculated its serialized size.
     * @param current_alignment Buffer alignment.
     * @return Serialized size.
     */
    static size_t get_cdr_serialize_size(
            const AmlipIdDataType& data,
            size_t current_alignment = 0);

    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    static size_t get_key_max_cdr_serialized_size(
            size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has been defined for this type
     */
    static bool is_key_defined();

    static bool is_bounded();

    static bool is_plain();

    static bool construct_sample(
            void* memory);

protected:

    std::array<uint8_t, NAME_SIZE> name_;

    std::array<uint8_t, RAND_SIZE> rand_id_;

    static const AmlipIdDataType UNDEFINED_ID_;
};

//! \c AmlipIdDataType to stream serializator
std::ostream& operator <<(
        std::ostream& os,
        const AmlipIdDataType& id);

} /* namespace types */
} /* namespace amlip */
} /* namespace eprosima */

#endif // AMLIP__SRC_CPP_AMLIPCPP_AMLIPIDDATATYPE_HPP
