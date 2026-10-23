# SetSimtGridDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:53:49.246Z pushedAt=2026-10-15T03:48:05.107Z -->

## Function

Sets the dimensions of the SIMT thread grid, that is, the number of thread blocks inside the thread grid of the Vector compute units participating in the computation, represented by the **Dim3** structure. **Dim3** is a structure containing three **uint32** fields **x**, **y**, and **z**, which represent the number of thread blocks of a thread grid in the three dimensions **x**, **y**, and **z**.

For example: **block\_dim.x**, **block\_dim.y**, and **block\_dim.z** represent the number of thread blocks of the thread grid in the three dimensions **x**, **y**, and **z**, respectively.

## Function Prototype

```cpp
ge::graphStatus SetSimtGridDim(const Dim3 &grid_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|grid_dim|Input|Dimensions of the thread grid. **Dim3** is a structure containing three **uint32** fields **x**, **y**, and **z**, which represent the number of thread blocks of a thread grid in the three dimensions **x**, **y**, and **z**.|

The **Dim3** structure is defined as follows:

```cpp
struct Dim3 {
  uint32_t x, y, z;
  Dim3(const uint32_t dim3_x, const uint32_t dim3_y = 1, const uint32_t dim3_z = 1) : x(dim3_x), y(dim3_y), z(dim3_z) {
  }
};
```

Note: **Dim3** is a structure containing three **uint32** fields **x**, **y**, and **z**. In SIMT, it can represent the number of threads of a thread block in the three dimensions **x**, **y**, and **z**, or the number of thread blocks of a thread grid in the three dimensions **x**, **y**, and **z**.

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
gert::Dim3 grid_dim(2, 3);
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetSimtGridDim(grid_dim);
  // ...
}
```
