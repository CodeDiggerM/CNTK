#pragma once
//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//
#include "CNTKLibrary.h"

#include <iostream>
#include <stdio.h>
#include <string>

#pragma warning(push, 0)
#include <graphid.pb.h>
#include <google/protobuf/util/json_util.h>
#pragma warning(pop)

extern void RetrieveInputBuffers(
    CNTK::FunctionPtr evalFunc,
    std::unordered_map<std::wstring, std::vector<float>>& inputs);

extern void ExecuteModel(
    CNTK::FunctionPtr evalFunc,
    std::unordered_map<std::wstring, std::vector<float>>& inputs,
    std::unordered_map<std::wstring, std::vector<float>>& outputs);

extern void DumpAsJson(
    const google::protobuf::Message& message,
    const std::string& filename);

extern void DumpAsBinary(
    const google::protobuf::Message& message,
    const std::string& filename);

extern int MAX_BASE64_EXPORT_LENGTH;

namespace GRAPHIR
{
    const graphIR::Graph* Serialize(const CNTK::FunctionPtr& modelFuncPtr);
    const CNTK::FunctionPtr Deserialize(const graphIR::Graph* message);
}
