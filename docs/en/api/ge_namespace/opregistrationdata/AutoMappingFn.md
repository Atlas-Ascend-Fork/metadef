# AutoMappingFn

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:11:23.022Z pushedAt=2026-10-15T07:29:17.889Z -->

## Function

Automatic mapping callback function.

## Function Prototype

```cpp
Status AutoMappingFn(const google::protobuf::Message *op_src, ge::Operator &op)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_src|Input|Operator in the original model before conversion, containing the attributes of the operator in the original model.|
|op|Input|Operator adapted to the AI processor.|

For details about the **Operator** class, see *[GE Graph Engine API](https://gitcode.com/cann/ge/blob/9.2.0/docs/zh/api/graph_engine_api/README.md)*.

## Constraints

If the attributes of the original TensorFlow operator and the operator adapted to the AI processor cannot be mapped one-to-one, the **AutoMappingFn** function cannot be applied to the callback function [ParseParamsByOperatorFn](ParseParamsByOperatorFn.md). In this scenario, use the [AutoMappingByOpFn](AutoMappingByOpFn.md) API in the callback function [ParseParamsByOperatorFn](ParseParamsByOperatorFn.md) to automatically parse the attributes that can be mapped successfully. For a usage example, see [Example](AutoMappingByOpFn.md#example).
