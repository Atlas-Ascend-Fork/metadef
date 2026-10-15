# Build

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:48:13.648Z pushedAt=2026-10-15T03:48:04.972Z -->

## Function

Constructs a **TilingParseContext** based on the previous settings and returns a **ContextHolder<TilingParseContext\>** object.

## Function Prototype

```cpp
ContextHolder<TilingParseContext> Build()
```

## Parameters

None

## Return Value

Returns a **ContextHolder<TilingParseContext\>** object, through whose **GetContext\(\)** method the **TilingParseContext** pointer can be obtained.

## Constraints

- For all parameters passed by pointers, the memory ownership belongs to the caller. The caller must ensure that these pointers remain valid throughout the entire lifetime of the **ContextHolder** object.
- When **ContextHolder** is destructed, its internal context resources are automatically released. Do not manually release the pointer returned by **GetContext\(\)**.

## Example

```cpp
#include "base/context_builder/op_tiling_parse_context_builder.h"
const char* json_data = R"({"block_dim": 16, "stream_num": 1})";
uint8_t tmp_platform_info[] = {1, 2, 3, 4, 5, 6, 7}; // Fake data.
uint8_t tmp_compile_info[] = {1, 2, 3, 4, 5, 6, 7}; // Fake data.
OpTilingParseContextBuilder ctx_builder;
auto holder = ctx_builder.OpName("tmp")
                  .OpType("DIY")
                  .IONum(4, 1)
                  .InputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .InputTensorDesc(1, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .InputTensorDesc(2, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .InputTensorDesc(3, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .OutputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_NCDHW, ge::FORMAT_RESERVED)
                  .CompiledJson(json_data)
                  .CompiledInfo(tmp_compile_info)
                  .PlatformInfo(tmp_platform_info)
                  .Build();
auto ctx = holder.GetContext();
EXPECT_NE(ctx, nullptr);
auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
EXPECT_NE(ctx_compute_node_info, nullptr);
EXPECT_EQ(ctx->GetInputDesc(0)->GetOriginFormat(), ge::FORMAT_NCDHW);
EXPECT_EQ(ctx->GetInputDesc(0)->GetStorageFormat(), ge::FORMAT_RESERVED);
EXPECT_EQ((void *) ctx->GetPlatformInfo(), (void *) tmp_platform_info);
EXPECT_EQ((void *) ctx->GetPlatformInfo(), (void *) tmp_platform_info);
EXPECT_EQ(std::string(ctx->GetCompiledJson()), std::string(json_data.c_str()));
EXPECT_EQ(ctx->GetCompiledInfo<uint8_t>(), tmp_compile_info);
```
