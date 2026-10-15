# Tiling

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:33:37.199Z pushedAt=2026-10-15T03:48:04.943Z -->

## Function

Registers the Tiling function of an operator.

You need to write a function of the **TilingKernelFunc** type for the operator and register it through this API. You can also specify the maximum length of the tiling data, which defaults to 2048 bytes.

The **TilingKernelFunc** type is defined as follows:

```cpp
using TilingKernelFunc = UINT32 (*)(TilingContext *);
```

## Function Prototype

```cpp
OpImplRegisterV2 &Tiling(TilingKernelFunc tiling_func, size_t max_tiling_data_size = 2048)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|tiling_func|Input|Custom Tiling function to be registered, which is of the **TilingKernelFunc** type.|
|max_tiling_data_size|Input|Maximum length of the tiling data, with a default value of 2048 bytes.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **Tiling** function **tiling\_func**.

## Constraints

None
