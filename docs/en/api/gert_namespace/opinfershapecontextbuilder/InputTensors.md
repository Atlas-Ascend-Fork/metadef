# InputTensors

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:37:27.508Z pushedAt=2026-10-15T03:48:04.949Z -->

## Function

Sets the input tensor pointers. During shape inference, the corresponding input tensor pointers can be obtained through the **InferShapeContext** constructed by this **Builder** class. For data-dependent operators, the **TensorData** in the input tensor corresponding to the data dependency must be set to a correct host address. For non-data-dependent operators, the **TensorData** of the tensor must be set to a null pointer.

## Function Prototype

```cpp
OpInferShapeContextBuilder &InputTensors(const std::vector<gert::Tensor *> &inputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|inputs|Input|Array of input tensor pointers. Ownership is managed by the caller, who must ensure that the lifetime of the input pointers is longer than that of the **ContextHolder** object produced by **Build**.|

## Return Value

**OpInferShapeContextBuilder** object, which is used for chained calls.

## Constraints

Before calling the **Build** method, you must call this API; otherwise, the constructed **InferShapeContext** will contain undefined data.
