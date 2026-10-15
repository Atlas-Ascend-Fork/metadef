# FusionParseParamsFn

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T01:41:14.344Z pushedAt=2026-10-15T03:48:04.725Z -->

## Function

Registers the function for parsing fusion operator attributes.

## Function Prototype

```cpp
OpRegistrationData &FusionParseParamsFn(const FusionParseParamFunc &fusionParseParamFn)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**fusionParseParamFn**|Input|Function for parsing fusion operator attributes. See the callback function **FusionParseParamFunc**.|

## Constraints

For fusion operator plugins, the **FusionParseParamsFn** API will be deprecated in later versions. Use the [FusionParseParamsFn (Overload)](fusionparseparamsfn_overload.md) API to parse fusion operator attributes.

## Callback Function FusionParseParamFunc

Users customize and implement the **FusionParseParamFunc** class function to complete the mapping of attributes from the original model to the model adapted to the AI processor, and fill the results into the **Operator** class.

```cpp
Status FusionParseParamFunc(const  vector<const google::protobuf::Message *> &v_op_origin, ge::Operator  &op_dest)
```

**Table 1** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**v_op_origin**|Input|A protobuf-format data structure within a scope (derived from the prototxt file of the original model), containing operator attribute information.|
|**op_dest**|Output|Fusion operator data structure, which stores fusion operator information.|

For details about the **Operator** class, see [*GE Graph Engine API*](https://gitcode.com/cann/ge/blob/master/docs/zh/api/graph_engine_api/README.md).
