# GetContext

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:39:36.010Z pushedAt=2026-10-15T03:48:04.848Z -->

## Function

Obtains the corresponding **Context** pointer based on the specified type.

## Function Prototype

```cpp
template<typename ContextTypeT>
ContextTypeT *GetContext()
```

## Parameters

**ContextTypeT** is a generic that includes the following types of **Context**:

- InferDataTypeContext;
- InferShapeContext;
- InferShapeRangeContext;
- KernelContext;
- TilingContext;
- TilingParseContext.

## Return Value

Returns a pointer to the **Context**. The relationships among **ContextBuilder**, **ContextHolder**, and **Context** are shown in the following table:

**Table 1** Relationships among ContextBuilder, ContextHolder, and Context

|ContextBuilder|Holder|Context|
|--|--|--|
|OpInferDataTypeContextBuilder|ContextHolder\<InferDataTypeContext>|InferDataTypeContext|
|OpInferShapeContextBuilder|ContextHolder\<InferShapeContext>|InferShapeContext|
|OpInferShapeRangeContextBuilder|ContextHolder\<InferShapeRangeContext>|InferShapeRangeContext|
|OpKernelContextBuilder|ContextHolder\<KernelContext>|KernelContext|
|OpTilingContextBuilder|ContextHolder\<TilingContext>|TilingContext|
|OpTilingParseContextBuilder|ContextHolder\<TilingParseContext>|TilingParseContext|

## Constraints

None

## Example

```cpp
OpInferDataTypeContextBuilder ctx_builder;
ge::DataType dtype0 = ge::DT_FLOAT;
ge::DataType dtype1 = ge::DT_FLOAT16;
ge::DataType dtype2 = ge::DT_FLOAT;
ge::DataType dtype3 = ge::DT_FLOAT16;
ge::DataType dtype4 = ge::DT_FLOAT16;
std::vector<ge::DataType> input_dtype_ref = {dtype0, dtype1, dtype2, dtype3};
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
```
