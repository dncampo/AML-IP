// Copyright 2023 Proyectos y Sistemas de Mantenimiento SL (eProsima).
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

////////////////////////////////////////////////////////
// Binding for class AsyncEdgeNode
////////////////////////////////////////////////////////

// Import parent class
%import(module="amlip_swig") "amlip_cpp/node/ParentNode.hpp";

// Generate directors for the virtual methods in the listener
// IMPORTANT: this statement must be before including the hpp
%feature("director") eprosima::amlip::node::InferenceListener;

%shared_ptr(eprosima::amlip::node::InferenceListener);

%ignore eprosima::amlip::node::AsyncEdgeNode::request_inference(const eprosima::amlip::types::InferenceDataType& );

%{
#include <amlip_cpp/node/AsyncEdgeNode.hpp>
%}

// Include the class interfaces
%include <amlip_cpp/node/AsyncEdgeNode.hpp>
