# Build

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:41:15.046Z pushedAt=2026-10-15T03:48:04.957Z -->

## Function

Builds **KernelContext** based on the previous settings and returns a **ContextHolder<KernelContext\>** object.

## Function Prototype

```cpp
ContextHolder<KernelContext> Build()
```

## Parameters

None

## Return Value

Returns a **ContextHolder<KernelContext\>** object. Call the **GetContext\(\)** method to obtain the **KernelContext** pointer.

## Constraints

- For all parameters passed by pointers, the memory ownership belongs to the caller. The caller must ensure that these pointers remain valid throughout the entire lifetime of the **ContextHolder** object.
- When **ContextHolder** is destructed, its internal context resources are automatically released. Do not manually release the pointer returned by **GetContext\(\)**.

## Example

```cpp
#include "base/context_builder/op_kernel_run_context_builder.h"
OpKernelContextBuilder ctx_builder;
gert::StorageShape shape0 = {{10, 20}, {10, 20}};
auto holder = ctx_builder.OpType("Add")
                  .OpName("add_1")
                  .IONum(2, 1)
                  .InputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                  .InputTensorDesc(1, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                  .OutputTensorDesc(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                  .Inputs({&shape0, &shape0})
                  .Outputs({&shape0})
                  .Build();
auto ctx = reinterpret_cast<KernelContext *>(holder.GetContext());
EXPECT_NE(ctx, nullptr);
auto ctx_compute_node_info = static_cast<const gert::ComputeNodeInfo *>(ctx->GetComputeNodeExtend());
EXPECT_NE(ctx_compute_node_info, nullptr);
EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeType()), std::string("Add"));
EXPECT_EQ(std::string(ctx_compute_node_info->GetNodeName()), std::string("add_1"));
EXPECT_EQ(ctx_compute_node_info->GetIrInputsNum(), 2);
EXPECT_EQ(ctx_compute_node_info->GetIrOutputsNum(), 1);
EXPECT_EQ(ctx_compute_node_info->GetInputsNum(), 2);
EXPECT_EQ(ctx_compute_node_info->GetOutputsNum(), 1);
const CompileTimeTensorDesc *info_input_0 = ctx_compute_node_info->GetInputTdInfo(0);
EXPECT_NE(info_input_0, nullptr);
EXPECT_EQ(info_input_0->GetStorageFormat(), ge::FORMAT_FRACTAL_NZ);
EXPECT_EQ(info_input_0->GetOriginFormat(), ge::FORMAT_ND);
EXPECT_EQ(ctx->GetInput(0)->GetPointer<gert::StorageShape>(), &shape0);
EXPECT_EQ(ctx->GetInput(1)->GetPointer<gert::StorageShape>(), &shape0);
EXPECT_EQ(ctx->GetOutput(0)->GetPointer<gert::StorageShape>(), &shape0);
```
