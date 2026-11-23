# gert\_TilingContextBuilder\_SetSimtGridDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:03:55.563Z pushedAt=2026-10-15T03:48:04.668Z -->

## Function

Sets the SIMT grid dimension when constructing a **TilingContext** with **OpTilingContextBuilder**. This corresponds to the weak-symbol C API and is equivalent to **OpTilingContextBuilder::SimtGridDim**. This is a weak-symbol bridging API declared with C linkage (extern "C"), but its parameter `grid_dim` is of the C++ type `gert::Dim3`, so it can only be called from C++ code and is not a pure C API that can be called directly from C source.

## Function Prototype

```cpp
uint32_t __attribute__((weak)) gert_TilingContextBuilder_SetSimtGridDim(void *builder, const gert::Dim3 *grid_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|builder|Input|Pointer to **OpTilingContextBuilder**.|
|grid_dim|Input|SIMT grid dimension.|

## Return Value

Status code. **0** indicates success.

## Constraints

None

## Example

```cpp
OpTilingContextBuilder ctx_builder;
gert::Dim3 grid_dim(4, 5);
ret = gert_TilingContextBuilder_SetSimtGridDim(reinterpret_cast<void *>(&ctx_builder4), &grid_dim);
```
