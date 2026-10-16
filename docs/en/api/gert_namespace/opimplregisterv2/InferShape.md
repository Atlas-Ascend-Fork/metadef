# InferShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:29:00.463Z pushedAt=2026-10-15T03:48:04.936Z -->

## Function

Registers the **InferShape** function of an operator.

You need to write a function of the **InferShapeKernelFunc** type for the operator and register it using this API.

The **InferShapeKernelFunc** type is defined as follows:

```cpp
using InferShapeKernelFunc = UINT32 (*)(InferShapeContext *);
```

The prototype of the **InferShape** function is fixed. It accepts an **InferShapeContext** object as input, on which you can obtain the shape pointers of the inputs and outputs, among other content (the input, output, and attribute information defined in the operator prototype). After **InferShape** succeeds, it returns **ge::GRAPH\_SUCCESS**; any other return value is considered an inference failure. After an inference failure, the execution process ends and exits.

## Function Prototype

```cpp
OpImplRegisterV2 &InferShape(InferShapeKernelFunc infer_shape_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|infer_shape_func|Input|Custom **InferShape** function to register, which is of the **InferShapeKernelFunc** type.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **InferShape** function **infer\_shape\_func**.

## Constraints

None
