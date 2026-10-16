# TilingDataSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:47:02.609Z pushedAt=2026-10-15T03:48:04.970Z -->

## Function

Sets the size of the operator's **TilingData**. After the size is set, memory of the corresponding size is allocated to store the operator's **TilingData**. Compared with [TilingData](TilingData.md), when this API is called, the ownership of the generated **TilingData** pointer belongs to **ContextHolder**, and the caller does not need to manage the lifecycle of the **TilingData**.

Note that this API is mutually exclusive with **TilingData**. If both **TilingDataSize** and **TilingData** are called, the API called later overrides the result of the previous call, and the latest one takes effect.

## Function Prototype

```cpp
OpTilingContextBuilder &TilingDataSize(size_t tiling_data_size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|tiling_data_size|Output|Tiling data size.|

## Return Value

**TilingContextBuilder** object, which is used for chained calls.

## Constraints

Before calling the **Build** method, you must set **TilingData** or **TilingDataSize**; otherwise, the constructed **TilingContext** will contain undefined data.
