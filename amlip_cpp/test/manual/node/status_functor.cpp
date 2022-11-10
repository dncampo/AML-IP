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
 * @file status.cpp
 *
 */

#include <thread>

#include <cpp_utils/Log.hpp>
#include <cpp_utils/event/SignalEventHandler.hpp>

#include <amlip_cpp/types/id/AmlipIdDataType.hpp>
#include <amlip_cpp/node/StatusNode.hpp>

class MyCustomStatusFunctor : public eprosima::amlip::node::StatusFunctor
{

public:

    MyCustomStatusFunctor(const eprosima::amlip::types::AmlipIdDataType& node_id)
        : node_id_(node_id)
    {
        // Do nothing
    }

    void operator() (const eprosima::amlip::types::StatusDataType& status) const override
    {
        logUser(
            AMLIPCPP_MANUAL_TEST,
            "Status: " << status << " received by :" << node_id_ << ".");
    }

protected:

    eprosima::amlip::types::AmlipIdDataType node_id_;
};

int main(
        int argc,
        char** argv)
{
    // initialize the random number generator
    srand (time(NULL));

    // Activate log
    eprosima::utils::Log::SetVerbosity(eprosima::utils::Log::Kind::Info);

    logUser(AMLIPCPP_MANUAL_TEST, "Starting Manual Test Status Node execution. Creating Node...");

    {
        // Create Status Node
        eprosima::amlip::node::StatusNode status_node("TestStatusNode");

        logUser(AMLIPCPP_MANUAL_TEST, "Node created: " << status_node << ". Processing data asynchronously...");

        // Create Functor
        MyCustomStatusFunctor my_object_functor(status_node.id());

        status_node.process_status_async(my_object_functor);

        logUser(AMLIPCPP_MANUAL_TEST, "Already processing status data. Waiting SIGINT (C^)...");

        eprosima::utils::event::SignalEventHandler<eprosima::utils::event::Signal::sigint> sigint_handler;
        sigint_handler.wait_for_event();

        logUser(AMLIPCPP_MANUAL_TEST, "SIGINT received. Destroying entities...");
    }

    logUser(AMLIPCPP_MANUAL_TEST, "Finishing Manual Test Status Node execution.");

    return 0;
}
