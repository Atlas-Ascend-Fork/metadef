# ParseParamsFn

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:12:51.920Z pushedAt=2026-10-15T07:29:17.893Z -->

## Function

Registers a function for parsing operator attributes.

## Function Prototype

```cpp
OpRegistrationData &ParseParamsFn(const ParseParamFunc &parseParamFn)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|parseParamFn|Input|Function **ParseParamFunc** for parsing operator attributes. See the callback function **ParseParamFunc**. For the TensorFlow framework, if the original TensorFlow framework operator attributes correspond one-to-one with the operator attributes in the model adapted to the AI processor (with the same number and order of attributes), you can directly use the **AutoMappingFn** function to implement automatic mapping.|

## Constraints

For custom operator plugins, **ParseParamsFn** will be deprecated in later versions. Use the [ParseParamsByOperatorFn](ParseParamsByOperatorFn.md) API to parse operator attributes.

If you have already developed an operator plugin using the **ParseParamsFn** API, perform the following operations to adapt to the new API:

1. Re-develop the operator plugin using the [ParseParamsByOperatorFn](ParseParamsByOperatorFn.md) API.
2. Re-compile the custom operator project based on the compilation script of the new-version custom operator sample project.

## Callback Function ParseParamFunc

Users customize and implement the **FusionParseParamFunc** class function to map the operator attributes in the original model to the operator attributes in the model adapted to the AI processor, and fill the results into the **Operator** class.

```cpp
using ParseParamFunc = std::function<domi::Status(const google::protobuf::Message *, ge::Operator &)>
```

- The first parameter is an input, a protobuf-format data structure (derived from the prototxt file of the original model) that contains operator attribute information.
- The second parameter is an output, the operator data structure of the model adapted to the AI processor, which stores operator information. For details about the **Operator** class, see *[GE Graph Engine API](https://gitcode.com/cann/ge/blob/9.2.0/docs/zh/api/graph_engine_api/README.md)*.
