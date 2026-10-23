# SimtGridDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:46:37.233Z pushedAt=2026-10-15T03:48:04.968Z -->

## Function

Sets the dimensions of the SIMT thread grid, that is, the number of thread blocks within the thread grid of the Vector compute units participating in the computation, represented by the **Dim3** structure. **Dim3** is a structure containing three **uint32** fields, **x**, **y**, and **z**, which represent the number of thread blocks of a grid in the x, y, and z dimensions. The operator tiling function can obtain the corresponding **Dim3** pointer through the context **TilingContext** constructed by this **Builder** class.

For example: **block\_dim.x**, **block\_dim.y**, and **block\_dim.z** represent the number of thread blocks of the thread grid in the x, y, and z dimensions, respectively.

## Function Prototype

```cpp
OpTilingContextBuilder &SimtGridDim(const gert::Dim3 *grid_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|grid_dim|Input|Sets the input grid dim pointer.|

## Return Value

**OpTilingContextBuilder** object, which is used for chained calls.

## Constraints

- Before calling the **Build** method, **InputTensors** must be set; otherwise, the constructed **TilingContext** will contain undefined data.
- For parameters passed by pointers (**gert::Dim3\***), the memory ownership belongs to the caller; the caller must ensure that the pointers remain valid throughout the lifetime of the **ContextHolder** object.
