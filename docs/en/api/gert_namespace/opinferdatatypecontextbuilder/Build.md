# Build

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:34:36.883Z pushedAt=2026-10-15T03:48:04.945Z -->

## Function

Builds **InferDataTypeContext** based on the previous settings and returns a **ContextHolder<InferDataTypeContext\>** object.

## Function Prototype

```cpp
ContextHolder<InferDataTypeContext> Build()
```

## Parameters

None

## Return Value

Returns a **ContextHolder<InferDataTypeContext\>** object. The **InferDataTypeContext** pointer can be obtained by calling the **GetContext\(\)** method.

## Constraints

- For all parameters passed to **OpInferDataTypeContextBuilder** through pointers, the memory ownership belongs to the caller. The caller must ensure that these pointers remain valid throughout the entire lifetime of the **ContextHolder** object.
- When **ContextHolder** is destructed, the internal context resources are automatically released. Do not manually release the pointer returned by **GetContext\(\)**.

## Example

```cpp
#include "base/context_builder/op_infer_datatype_context_builder.h"
OpInferDataTypeContextBuilder ctx_builder;
ge::DataType dtype0 = ge::DT_FLOAT;
ge::DataType dtype1 = ge::DT_FLOAT16;
ge::DataType dtype2 = ge::DT_FLOAT;
ge::DataType dtype3 = ge::DT_FLOAT16;
ge::DataType dtype4 = ge::DT_FLOAT16;
std::vector<ge::DataType *> input_dtype_ref = {&dtype0, &dtype1, &dtype2, &dtype3};
std::vector<ge::DataType *> output_dtype_ref = {&dtype4};
auto holder = ctx_builder.OpType("Concat")
                  .OpName("concat_1")
                  .IOInstanceNum({4}, {1})
                  .InputTensorDesc(0, dtype0, ge::FORMAT_ND, ge::FORMAT_ND)
                  .InputTensorDesc(1, dtype1, ge::FORMAT_ND, ge::FORMAT_ND)
                  .InputTensorDesc(2, dtype2, ge::FORMAT_ND, ge::FORMAT_ND)
                  .InputTensorDesc(3, dtype3, ge::FORMAT_ND, ge::FORMAT_ND)
                  .OutputTensorDesc(0, ge::FORMAT_ND, ge::FORMAT_ND)
                  .Build();
auto ctx = holder.GetContext();
EXPECT_NE(ctx, nullptr);
auto ctx_compute_node_info = ctx->GetComputeNodeInfo();
EXPECT_NE(ctx_compute_node_info, nullptr);
EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("Concat"));
EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("concat_1"));
EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 1);
EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 4);
EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
const CompileTimeTensorDesc *info_input_0 = ctx_compute_node_info->GetInputTdInfo(0);
EXPECT_NE(info_input_0, nullptr);
EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_ND);
EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_ND);
ge::DataType expected_datatype_0 = ge::DT_FLOAT;
ge::DataType expected_datatype_1 = ge::DT_FLOAT16;
EXPECT_EQ(ctx->GetInputDataType(0), expected_datatype_0);
EXPECT_EQ(ctx->GetInputDataType(1), expected_datatype_1);
EXPECT_EQ(ctx->GetInputDataType(2), expected_datatype_0);
EXPECT_EQ(ctx->GetInputDataType(3), expected_datatype_1);
EXPECT_EQ(ctx->GetOutputDataType(0), ge::DT_MAX);
```
