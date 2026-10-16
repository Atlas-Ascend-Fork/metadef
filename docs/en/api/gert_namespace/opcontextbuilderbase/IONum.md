# IONum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:23:47.416Z pushedAt=2026-10-15T03:48:04.926Z -->

## Function

Sets the number of input and output IR prototypes of an operator, which is used to construct the **ComputeNodeInfo** information in the base class **ExtendedKernelContext** of each subclass **Context**. By default, the number of input and output instances for each IR prototype is 1.

## Function Prototype

```cpp
T &IONum(size_t input_ir_num, size_t output_ir_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|input_ir_num|Input|Number of input IR prototypes.|
|output_ir_num|Input|Number of output IR prototypes.|

## Return Value

Returns a reference to the subclass object of type **T**, which supports chained calls on the subclass.

## Constraints

This API is mutually exclusive with the [IOInstanceNum](IOInstanceNum.md) API. You only need to call one of the two APIs, and the API called first takes precedence.
