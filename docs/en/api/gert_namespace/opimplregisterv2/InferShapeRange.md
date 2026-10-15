# InferShapeRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:29:26.193Z pushedAt=2026-10-15T03:48:04.936Z -->

## Function

Registers the **InferShapeRange** function of an operator.

You need to write a function of the **InferShapeRangeKernelFunc** type for the operator and register it using this API.

The **InferShapeRangeKernelFunc** type is defined as follows:

```cpp
using InferShapeRangeKernelFunc = UINT32 (*)(InferShapeRangeContext *);
```

The prototype of the **InferShapeRange** function is fixed. It accepts an **InferShapeRangeContext** type as input, on which you can obtain the shape pointers of the inputs and outputs, and other content (the input, output, and attribute information defined in the operator prototype). After **InferShapeRange** succeeds, it returns **ge::GRAPH\_SUCCESS**; other return values are considered inference failures. After an inference failure, the execution process ends and exits.

## Function Prototype

```cpp
OpImplRegisterV2 &InferShapeRange(InferShapeRangeKernelFunc infer_shape_range_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|infer_shape_range_func|Input|Custom **infer_shape_range_func** function to be registered, which is of the **InferShapeRangeKernelFunc** type.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **InferShapeRange** function **infer\_shape\_range\_func**.

## Constraints

None
