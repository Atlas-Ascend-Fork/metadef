# DeterministicLevel

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:43:50.850Z pushedAt=2026-10-15T03:48:04.963Z -->

## Function

Sets the deterministic computation level.

## Function Prototype

```cpp
OpTilingContextBuilder &DeterministicLevel(int32_t deterministic_level)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|deterministic_level|Input|Deterministic computation level (**0** for non-deterministic, **1** for deterministic, **2** for strong consistency, and **3** for batch consistency).|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, this API must be called; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
