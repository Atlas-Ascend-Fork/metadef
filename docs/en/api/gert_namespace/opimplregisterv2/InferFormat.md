# InferFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:28:02.909Z pushedAt=2026-10-15T03:48:04.935Z -->

## Function

Registers the **InferFormat** function of an operator.

For some format-sensitive cube operators, using an internal format that better adapts to the underlying hardware can bring significant performance benefits. Therefore, developers need to implement and register the **InferFormat** function.

## Function Prototype

```cpp
OpImplRegisterV2 &InferFormat(InferFormatFunc infer_format_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|infer_format_func|Input|Custom **InferFormat** function to register, which is of the type **InferFormatFunc**. The **InferFormatFunc** type is defined as follows:<br>`using InferFormatFunc = UINT32 (*)(InferFormatContext *context);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **InferFormat** function **infer\_format\_func**.

## Constraints

None
