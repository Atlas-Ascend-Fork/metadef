# gert\_TilingContextBuilder\_SetSimtBlockDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:03:24.057Z pushedAt=2026-10-15T03:48:04.667Z -->

## Function

Sets the SIMT Block dimension when constructing a **TilingContext** with **OpTilingContextBuilder**. This corresponds to the weak-symbol C API and is equivalent to **OpTilingContextBuilder::SimtBlockDim**. This is a weak-symbol bridging API declared with C linkage (extern "C"), but its parameter `block_dim` is of the C++ type `gert::Dim3`, so it can only be called from C++ code and is not a pure C API that can be called directly from C source.

## Function Prototype

```cpp
uint32_t __attribute__((weak)) gert_TilingContextBuilder_SetSimtBlockDim(void *builder, const gert::Dim3 *block_dim)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**builder**|Input|Pointer to **OpTilingContextBuilder**.|
|**block_dim**|Input|SIMT block dimension.|

## Return Value

Status code. **0** indicates success.

## Constraints

None

## Example

```cpp
OpTilingContextBuilder ctx_builder;
gert::Dim3 block_dim(2, 3);
ret = gert_TilingContextBuilder_SetSimtBlockDim(reinterpret_cast<void *>(&ctx_builder), &block_dim);
```
