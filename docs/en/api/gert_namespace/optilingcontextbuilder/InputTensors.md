# InputTensors

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:44:25.074Z pushedAt=2026-10-15T03:48:04.964Z -->

## Function

Sets the input tensor pointers so that during tiling computation, the corresponding input tensor pointers can be obtained through the **TilingContext** constructed by this **Builder** class.

## Function Prototype

```cpp
OpTilingContextBuilder &InputTensors(const std::vector<gert::Tensor *> &inputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|inputs|Input|Sets the input tensor pointers.|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, **InputTensors** must be set; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
