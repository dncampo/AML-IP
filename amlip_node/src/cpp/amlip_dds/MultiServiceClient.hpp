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

/**
 * @file MultiServiceClient.hpp
 */

#ifndef AMLIP__SRC_CPP_AMLIPDDS_MULTISERVICECLIENT_HPP
#define AMLIP__SRC_CPP_AMLIPDDS_MULTISERVICECLIENT_HPP

#include <amlip_dds/DirectWriter.hpp>
#include <amlip_dds/Reader.hpp>
#include <amlip_dds/Writer.hpp>

namespace eprosima {
namespace amlip {
namespace dds {

template <typename Task, typename TaskSolution>
class MultiServiceClient
{
public:

    MultiServiceClient(
        const std::string& multiservice_name,
        std::shared_ptr<Writer> request_availability_writer,
        std::shared_ptr<Reader> reply_available_reader,
        std::shared_ptr<Writer> task_target_writer,
        std::shared_ptr<DirectWriter> task_reader,
        std::shared_ptr<Reader> solution_reader);

    TaskSolution publish_task(Task data);

    void stop();
};

} /* namespace dds */
} /* namespace amlip */
} /* namespace eprosima */

#endif /* AMLIP__SRC_CPP_AMLIPDDS_MULTISERVICECLIENT_HPP */
