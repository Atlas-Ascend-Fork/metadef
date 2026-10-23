# TilingData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:46:54.393Z pushedAt=2026-10-15T03:48:04.970Z -->

## Function

Sets the **TilingData** pointer of the operator, which is used to write **TilingData** into the pointer during operator tiling computation.

## Function Prototype

```cpp
OpTilingContextBuilder &TilingData(const gert::TilingData *tiling_data, gert::Chain::Deleter deleter = nullptr)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|tiling_data|Input|**TilingData** data pointer.|
|deleter|Input|Deleter for the tiling data. If the user explicitly passes the deleter, it is called to release the tiling data when **ContextHolder** is destructed. By default, it is not passed. It is recommended to use the **TilingDataSize** API.|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, you must set **TilingData** or **TilingDataSize**; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**void\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
