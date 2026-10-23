# SetSimtBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:53:11.593Z pushedAt=2026-10-15T03:48:05.105Z -->

## Function

Sets the dimension of the SIMT thread block, that is, the number of threads inside the thread block of the Vector computation unit involved in the computation, represented by the **Dim3** structure. **Dim3** is a structure containing three **uint32** fields, **x**, **y**, and **z**, which represent the number of threads of a block in the x, y, and z dimensions.

For example, **block\_dim.x**, **block\_dim.y**, and **block\_dim.z** represent the number of threads of the thread block in the x, y, and z dimensions, respectively.

## Function Prototype

```cpp
ge::graphStatus SetSimtBlockDim(const Dim3 &block_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|block_dim|Input|Dimension of the thread block, represented by the **Dim3** structure. **Dim3** is a structure containing three **uint32** fields, **x**, **y**, and **z**, which represent the number of threads of a block in the x, y, and z dimensions.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
gert::Dim3 block_dim(2, 3);
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetSimtBlockDim(block_dim);
  // ...
}
```
