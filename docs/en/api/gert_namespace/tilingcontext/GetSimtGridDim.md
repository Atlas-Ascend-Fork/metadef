# GetSimtGridDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:45:45.974Z pushedAt=2026-10-15T03:48:05.093Z -->

## Function

Obtains the dimensions of the SIMT thread grid, that is, the number of thread blocks inside the thread grid of the Vector compute unit participating in the computation, represented by a **Dim3** structure. **Dim3** is a structure containing three **uint32** fields, **x**, **y**, and **z**, which represent the number of thread blocks of a thread grid in the three dimensions x, y, and z.

For example: **block\_dim.x**, **block\_dim.y**, and **block\_dim.z** represent the number of thread blocks of the thread grid in the three dimensions x, y, and z, respectively.

## Function Prototype

```cpp
const Dim3 *GetSimtGridDim() const
```

## Parameters

None

## Return Value

Returns **grid\_dim**.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto grid_dim = context->GetSimtGridDim();
  // ...
}
```
