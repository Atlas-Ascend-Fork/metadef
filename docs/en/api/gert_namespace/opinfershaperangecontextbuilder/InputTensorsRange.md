# InputTensorsRange

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:39:30.666Z pushedAt=2026-10-15T03:48:04.954Z -->

## Function

Sets the range pointers of the input tensors. During shape range inference, the input tensor range pointers can be obtained through the context **InferShapeRangeContext** constructed by this **Builder** class, that is, the tensor with the maximum shape and the tensor with the minimum shape can be obtained.

## Function Prototype

```cpp
OpInferShapeRangeContextBuilder &InputTensorsRange(const std::vector<gert::Range<gert::Tensor> *> &inputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|inputs|Input|Array of the `gert::Range<gert::Tensor> *` type, which stores the tensor range pointers of each operator input. A tensor range contains the tensor with the maximum shape and the tensor with the minimum shape.|

## Return Value

**OpInferShapeRangeContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, this API must be called; otherwise, the constructed **InferShapeRangeContext** will contain undefined data.
- For parameters passed by pointer **\(gert::Tensor \*\)**, the memory ownership belongs to the caller; the caller must ensure that the pointer remains valid throughout the lifetime of the **ContextHolder** object.
