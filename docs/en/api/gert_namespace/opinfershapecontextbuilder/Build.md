# Build

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:37:23.168Z pushedAt=2026-10-15T03:48:04.950Z -->

## Function

Builds an **InferShapeContext** based on the previous settings and returns a **ContextHolder<InferShapeContext\>** object.

## Function Prototype

```cpp
ContextHolder<InferShapeContext> Build()
```

## Parameters

None

## Return Value

Returns a **ContextHolder<InferShapeContext\>** object. The **InferShapeContext** pointer can be obtained by calling the **GetContext\(\)** method.

## Constraints

- For all parameters passed to **OpInferShapeContextBuilder** through pointers, the memory ownership belongs to the caller. The caller must ensure that these pointers remain valid throughout the entire lifetime of the **ContextHolder** object.
- When **ContextHolder** is destructed, the internal context resources are automatically released. Do not manually release the pointer returned by **GetContext\(\)**.

## Example

```cpp
#include "base/context_builder/op_infer_shape_context_builder.h"
OpInferShapeContextBuilder ctx_builder;
StorageShape shape0 = {{1, 2, 3, 4}, {4, 3, 2, 1}};
StorageShape shape1 = {{2, 3, 4, 5}, {5, 4, 3, 2}};
StorageShape shape2 = {{3, 4, 5, 6}, {6, 5, 4, 3}};
StorageShape shape3 = {{4, 5, 6, 7}, {7, 6, 5, 4}};
StorageFormat format{FORMAT_ND, FORMAT_FRACTAL_NZ, {}};
gert::Tensor tensor0{shape0, format, ge::DT_FLOAT};
gert::Tensor tensor1{shape1, format, ge::DT_FLOAT};
gert::Tensor tensor2{shape2, format, ge::DT_FLOAT};
gert::Tensor tensor3{shape3, format, ge::DT_FLOAT};
std::vector<gert::Tensor *> input_tensors = {&tensor0, &tensor1, &tensor2, &tensor3};
auto holder = ctx_builder.OpType("DIY")
                  .OpName("diy_1")
                  .IOInstanceNum({1, 1, 1, 1}, {1})
                  .OutputTensorDesc(0, ge::DT_FLOAT, ge::FORMAT_ND, ge::FORMAT_NCHW)
                  .InputTensors(input_tensors)
                  .Build();
auto ctx = holder.GetContext();
EXPECT_NE(ctx, nullptr);
auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
EXPECT_NE(ctx_compute_node_info, nullptr);
EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("DIY"));
EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("diy_1"));
EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 4);
EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 4);
EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
const CompileTimeTensorDesc *info_input_0 = ctx_compute_node_info->GetInputTdInfo(0);
EXPECT_NE(info_input_0, nullptr);
EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_FRACTAL_NZ);
EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_ND);
EXPECT_NE(ctx->GetInputShape(0), nullptr);
EXPECT_EQ(*(ctx->GetInputShape(0)), shape0.GetOriginShape());
EXPECT_NE(ctx->GetInputShape(1), nullptr);
EXPECT_EQ(*(ctx->GetInputShape(1)), shape1.GetOriginShape());
EXPECT_NE(ctx->GetInputShape(2), nullptr);
EXPECT_EQ(*(ctx->GetInputShape(2)), shape2.GetOriginShape());
EXPECT_NE(ctx->GetInputShape(3), nullptr);
EXPECT_EQ(*(ctx->GetInputShape(3)), shape3.GetOriginShape());
EXPECT_NE(ctx->GetOutputShape(0), nullptr);
EXPECT_EQ(ctx->GetOutputShape(0)->GetDimNum(), 0);
EXPECT_EQ(ctx->GetComputeNodeInfo()->GetOutputTdInfo(0)->GetDataType(), DT_FLOAT);
EXPECT_EQ(ctx->GetComputeNodeInfo()->GetOutputTdInfo(0)->GetOriginFormat(), FORMAT_ND);
EXPECT_EQ(ctx->GetComputeNodeInfo()->GetOutputTdInfo(0)->GetStorageFormat(), FORMAT_NCHW);
```
