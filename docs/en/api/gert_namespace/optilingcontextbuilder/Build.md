# Build

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:43:00.169Z pushedAt=2026-10-15T03:48:04.961Z -->

## Function

Constructs **TilingContext** based on the previous settings and returns a **ContextHolder<TilingContext\>** object.

## Function Prototype

```cpp
ContextHolder<TilingContext> Build()
```

## Parameters

None

## Return Value

Returns a **ContextHolder<TilingContext\>** object. The **TilingContext** pointer can be obtained by calling the **GetContext\(\)** method.

## Constraints

- For all parameters passed by pointers, the memory ownership belongs to the caller. The caller must ensure that these pointers remain valid throughout the entire lifetime of the **ContextHolder** object.
- When **ContextHolder** is destructed, the internal context resources are automatically released. Do not manually release the pointer returned by **GetContext\(\)**.

## Example

```cpp
#include "base/context_builder/op_tiling_context_builder.h"
auto workspace_size_holer = gert::ContinuousVector::Create<size_t>(4096);
auto ws_ptr = reinterpret_cast<gert::ContinuousVector *>(workspace_size_holer.get());
gert::Shape shape_0{1, 1, 1, 1, 1};
gert::Shape shape_1{10, 10, 10, 10, 20};
gert::Shape shape_2{1, 1, 1, 1, 1};
gert::Shape shape_3{10, 10, 10, 10, 20};
gert::Shape resultShape{10, 10, 10, 10, 20};
gert::StorageShape x({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
gert::StorageShape resultIn({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
gert::StorageShape gamma({1, 1, 1, 1, 1}, {1, 1, 1, 1, 1});
gert::StorageShape beta({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
gert::StorageShape result({10, 10, 10, 10, 20}, {10, 10, 10, 10, 20});
uint8_t data_x[1] = {9};
gert::Tensor x_tensor(x, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                      ge::DT_FLOAT, (void *) data_x);
gert::Tensor resultIn_tensor(resultIn, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                             TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr);
gert::Tensor gammax_tensor(gamma, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                           ge::DT_FLOAT, nullptr);
gert::Tensor beta_tensor(beta, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()}, TensorPlacement::kOnHost,
                         ge::DT_FLOAT, nullptr);
gert::Tensor result_tensor(result, {ge::FORMAT_NCDHW, ge::FORMAT_RESERVED, ExpandDimsType()},
                           TensorPlacement::kOnHost, ge::DT_FLOAT, nullptr);
uint8_t tmp_compile_info[] = XX; // XX represents fake data.
uint8_t tmp_platform_info[] = XX;// XX represents fake data.
int32_t deterministic = 1;
OpTilingContextBuilder ctx_builder;
auto holder = ctx_builder.OpName("tmp")
                  .OpType("DIY")
                  .IONum(4, 1)
                  .AppendAttr(int64_t(1))
                  .AppendAttr(bool(true))
                  .AppendAttr(float(0.3))
                  .AppendAttr(AscendString("my_info"))
                  .AppendAttr(std::vector<bool>({true, false, true}))
                  .AppendAttr(std::vector<int64_t>({1, 2, 3}))
                  .AppendAttr(std::vector<float>({0.1, 0.2, 0.3}))
                  .AppendAttr(std::vector<AscendString>({"123", "234"}))
                  .AppendAttr(std::vector<std::vector<int64_t>>({{1, 2, 3}, {4, 5, 6}}))
                  .TilingDataSize(100)
                  .Workspace(ws_ptr)
                  .CompileInfo(tmp_compile_info)
                  .Deterministic(deterministic)
                  .PlatformInfo(tmp_platform_info)
                  .InputTensors({&x_tensor, &resultIn_tensor, &gammax_tensor, &beta_tensor})
                  .OutputTensors({&result_tensor})
                  .Build();
auto ctx = holder.GetContext();
EXPECT_NE(ctx, nullptr);
auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
EXPECT_NE(ctx_compute_node_info, nullptr);
EXPECT_EQ(ctx->GetCompileInfo(), tmp_compile_info);
EXPECT_EQ(ctx->GetInputShape(0)->GetOriginShape(), shape_0);
EXPECT_EQ(ctx->GetInputShape(0)->GetStorageShape(), shape_0);
EXPECT_EQ(ctx->GetInputTensor(0)->GetAddr(), data_x);
EXPECT_EQ(ctx->GetInputTensor(0), &x_tensor);
EXPECT_EQ(ctx->GetInputTensor(0)->GetStorageShape(), x_tensor.GetStorageShape());
EXPECT_EQ(ctx->GetInputTensor(0)->GetOriginShape(), x_tensor.GetOriginShape());
EXPECT_EQ(ctx->GetInputTensor(0)->GetSize(), x_tensor.GetSize());
EXPECT_EQ(ctx->GetOutputShape(0)->GetOriginShape(), resultShape);
EXPECT_EQ(ctx->GetOutputShape(0)->GetStorageShape(), resultShape);
EXPECT_EQ(static_cast<void *>(ctx->GetWorkspaceSizes(4096)), static_cast<const void *>(ws_ptr->GetData()));
EXPECT_EQ(static_cast<void *>(ctx->GetPlatformInfo()), static_cast<void *>(tmp_platform_info));
EXPECT_EQ(ctx->GetDeterministic(), deterministic);
EXPECT_EQ(static_cast<void *>(ctx->GetRawTilingData()), static_cast<void *>(tmp_tiling_data.get()));
EXPECT_EQ(*(ctx->GetAttrs()->GetInt(0)), 1);
EXPECT_EQ(*(ctx->GetAttrs()->GetBool(1)), true);
EXPECT_FLOAT_EQ(*(ctx->GetAttrs()->GetFloat(2)), 0.3);
auto str_ptr = ctx->GetAttrs()->GetStr(3);
EXPECT_EQ(strcmp(str_ptr, "my_info"), 0);
auto bool_vec = ctx->GetAttrs()->GetAttrPointer<TypedContinuousVector<bool>>(4);
EXPECT_EQ(bool_vec->GetData()[0], true);
EXPECT_EQ(bool_vec->GetData()[1], false);
EXPECT_EQ(bool_vec->GetData()[2], true);
EXPECT_EQ(ctx->GetAttrs()->GetListInt(5)->GetData()[0], 1);
EXPECT_EQ(ctx->GetAttrs()->GetListInt(5)->GetData()[1], 2);
EXPECT_EQ(ctx->GetAttrs()->GetListInt(5)->GetData()[2], 3);
EXPECT_FLOAT_EQ(ctx->GetAttrs()->GetListFloat(6)->GetData()[0], 0.1);
EXPECT_FLOAT_EQ(ctx->GetAttrs()->GetListFloat(6)->GetData()[1], 0.2);
EXPECT_FLOAT_EQ(ctx->GetAttrs()->GetListFloat(6)->GetData()[2], 0.3);
auto int_vec_vec = ctx->GetAttrs()->GetListListInt(8);
EXPECT_EQ(((int64_t *) (int_vec_vec->Get(0)->GetData()))[0], 1);
EXPECT_EQ(((int64_t *) (int_vec_vec->Get(0)->GetData()))[1], 2);
EXPECT_EQ(((int64_t *) (int_vec_vec->Get(0)->GetData()))[2], 3);
EXPECT_EQ(((int64_t *) (int_vec_vec->Get(1)->GetData()))[0], 4);
EXPECT_EQ(((int64_t *) (int_vec_vec->Get(1)->GetData()))[1], 5);
EXPECT_EQ(((int64_t *) (int_vec_vec->Get(1)->GetData()))[2], 6);
```
