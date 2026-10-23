# AutoMappingFnDynamic

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:39:23.582Z pushedAt=2026-10-15T03:48:04.721Z -->

## Function

Automatic mapping callback function for operators with dynamic input/output.

## Function Prototype

```cpp
Status AutoMappingFnDynamic(const google::protobuf::Message *op_src, ge::Operator &op, std::map<std::string, std::pair<std::string, std::string>> dynamic_name_attr_value, int32_t in_pos = -1, int32_t out_pos = -1)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_src|Input|Operator in the original model before conversion, containing the attributes of the operator in the original model.|
|op|Input|Operator adapted to the AI processor.|
|dynamic_name_attr_value|Input|Describes the actual number of dynamic inputs and outputs. The key indicates whether the dynamic port is an input or an output. Key values: **in**: represents the input of the operator. **out**: represents the output of the operator.|
|in_pos|Input|Port ID of the dynamic input.|
|out_pos|Input|Port ID of the dynamic output.|

## Constraints

If the attributes of the original TensorFlow operator and the operator adapted to the AI processor cannot be mapped one-to-one, the AutoMappingFnDynamic function cannot be used in the callback function [ParseParamsByOperatorFn](ParseParamsByOperatorFn.md). In this scenario, use the [AutoMappingByOpFnDynamic](AutoMappingByOpFnDynamic.md) API in the callback function [ParseParamsByOperatorFn](ParseParamsByOperatorFn.md) to automatically parse the attributes that can be mapped successfully. For a usage example, see [Example](AutoMappingByOpFnDynamic.md#example).

## Sample Code

Sample code for dynamic input:

```cpp
// register MapStage op to GE
Status MapStageMapping(const google::protobuf::Message* op_src, ge::Operator& op) {
  map<string, pair<string, string>> value;
  value["in"] = pair<string, string>("values", "fake_dtypes");
  AutoMappingFnDynamic(op_src, op, value);
  return SUCCESS;
}

REGISTER_CUSTOM_OP("MapStage")
    .FrameworkType(TENSORFLOW)
    .OriginOpType("MapStage")
    .ParseParamsFn(MapStageMapping)
    .ImplyType(ImplyType::AI_CPU);
```

Sample code for dynamic output:

```cpp
Status AutoMappingFnSplit(const google::protobuf::Message* op_src, ge::Operator& op) {
  map<string, pair<string, string>> value;
  value["out"] = pair<string, string>("y", "num_split");
  AutoMappingFnDynamic(op_src, op, value);
  return SUCCESS;
}

REGISTER_CUSTOM_OP("Split")
    .FrameworkType(TENSORFLOW)
    .OriginOpType("Split")
    .ParseParamsFn(AutoMappingFnSplit)
    .ImplyType(ImplyType::TVM);
```
