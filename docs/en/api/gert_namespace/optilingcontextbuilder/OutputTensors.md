# OutputTensors

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:45:38.660Z pushedAt=2026-10-15T03:48:04.967Z -->

## Function

Sets the output tensor.

## Function Prototype

```cpp
OpTilingContextBuilder &OutputTensors(const std::vector<gert::Tensor *> &outputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|outputs|Input|Pointer array of output tensors.|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, **OutputTensors** must be set; otherwise, the constructed **TilingContext** will contain undefined data.
- The memory ownership of the parameters passed by pointers (**void\***) belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
