# Deterministic

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:43:24.189Z pushedAt=2026-10-15T03:48:04.963Z -->

## Function

Sets whether to enable deterministic computation.

## Function Prototype

```cpp
OpTilingContextBuilder &Deterministic(int32_t deterministic)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|deterministic|Input|Whether to enable deterministic computation (**1** : enable; **0**: disable).|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- This API must be called before calling the **Build** method; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
