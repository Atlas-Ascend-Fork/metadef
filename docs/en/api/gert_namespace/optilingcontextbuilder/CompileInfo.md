# CompileInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:43:20.034Z pushedAt=2026-10-15T03:48:04.962Z -->

## Function

Sets the **CompileInfo** pointer of the operator.

## Function Prototype

```cpp
OpTilingContextBuilder &CompileInfo(const void *compile_info)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|compile_info|Input|Compilation information **CompileInfo** pointer.|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, this API must be called; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
