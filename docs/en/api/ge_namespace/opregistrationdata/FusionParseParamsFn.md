# FusionParseParamsFn

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:11:50.132Z pushedAt=2026-10-15T07:29:17.890Z -->

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

For details about the **Operator** class, see *[GE Graph Engine API](https://gitcode.com/cann/ge/blob/9.2.0/docs/zh/api/graph_engine_api/README.md)*.
