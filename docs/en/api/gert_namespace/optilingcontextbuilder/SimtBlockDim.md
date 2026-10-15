# SimtBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:46:23.463Z pushedAt=2026-10-15T03:48:04.969Z -->

## Function

Sets the dimensions of the SIMT thread block, that is, the number of threads inside the thread block of the Vector compute unit participating in the computation, represented by the **Dim3** structure. **Dim3** is a structure containing three **uint32** fields, **x**, **y**, and **z**, which represent the number of threads of a block in the x, y, and z dimensions. The operator tiling function can obtain the corresponding **Dim3** pointer through the context **TilingContext** constructed by this **Builder** class.

For example, **block\_dim.x**, **block\_dim.y**, and **block\_dim.z** represent the number of threads of the thread block in the x, y, and z dimensions, respectively.

## Function Prototype

```cpp
OpTilingContextBuilder &SimtBlockDim(const gert::Dim3 *block_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|block_dim|Input|Sets the input block dim pointer.|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, **SimtBlockDim** must be set; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**gert::Dim3\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
