# FusionParseParamsFn (Overload)

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:11:16.401Z pushedAt=2026-10-15T07:29:17.889Z -->

## Function

Registers the function for parsing fusion operator attributes. It is an overload function of [FusionParseParamsFn](FusionParseParamsFn.md).

## Function Prototype

```cpp
OpRegistrationData &FusionParseParamsFn(const FusionParseParamByOpFunc &fusion_parse_param_fn)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**fusion_parse_param_fn**|Input|Function for parsing fusion operator attributes. See the callback function FusionParseParamByOpFunc.|

## Callback Function FusionParseParamByOpFunc

Users customize and implement the **FusionParseParamByOpFunc** class function to map attributes from the original model to the model adapted to the AI processor, and write the results into the **Operator** class.

```cpp
Status FusionParseParamByOpFunc(const std::vector<ge::Operator> &op_src,  ge::Operator &op_dest)
```

**Table 1** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_src|Input|Fusion operator data structure that stores the operator attributes of the original model within a group of scopes.|
|op_dest|Output|Fusion operator data structure that stores the fusion operator information.|

For details about the Operator class, see *[GE Graph Engine API](https://gitcode.com/cann/ge/blob/9.2.0/docs/zh/api/graph_engine_api/README.md)*.

## Example

```cpp
REGISTER_CUSTOM_OP(XXXXXX)
.FrameworkType(TENSORFLOW)
.FusionParseParamsFn(FusionParseParamsFn)
.OriginOpType(XXXXX)
.ImplyType(XXXXX);
```
