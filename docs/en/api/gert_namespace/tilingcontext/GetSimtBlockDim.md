# GetSimtBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:45:18.801Z pushedAt=2026-10-15T03:48:05.093Z -->

## Function

Obtains the dimensions of the SIMT thread block, that is, the number of threads inside the thread block of the Vector compute unit participating in the computation, represented by the **Dim3** structure. **Dim3** is a structure containing three **uint32** fields, **x**, **y**, and **z**, which represent the number of threads of a thread block in the three dimensions x, y, and z.

For example: **block\_dim.x**, **block\_dim.y**, and **block\_dim.z** represent the number of threads of the thread block in the three dimensions x, y, and z, respectively.

## Function Prototype

```cpp
const Dim3 *GetSimtBlockDim() const
```

## Parameters

None

## Return Value

Returns **block\_dim**.

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto block_dim = context->GetSimtBlockDim();
  // ...
}
```
