# ParseParamsByOperatorFn

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:12:26.499Z pushedAt=2026-10-15T07:29:17.892Z -->

## Function

Registers the function for parsing custom operator attributes.

## Function Prototype

```cpp
OpRegistrationData &ParseParamsByOperatorFn(const ParseParamByOpFunc &parse_param_by_op_fn)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|parse_param_by_op_fn|Input|Function for parsing custom operator attributes. See the callback function **ParseParamByOpFunc**.|

## Callback Function ParseParamByOpFunc

The user defines and implements the **ParseParamByOpFunc** class function to map operator attributes in the original model to attributes in the model adapted to the AI processor, and writes the results into the **Operator** class.

```cpp
Status ParseParamByOpFunc(const ge::Operator &op_origin, ge::Operator &op_dest)
```

**Table 1** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**op_origin**|Input|**Operator** class object defined by the framework, which contains the parsed custom operator attribute information in the original model.|
|**op_dest**|Output|Operator data structure in the model adapted to the AI processor, which stores the operator information.|

For details about the **Operator** class, see *[GE Graph Engine API](https://gitcode.com/cann/ge/blob/9.2.0/docs/zh/api/graph_engine_api/README.md)*.

## Constraints

None
