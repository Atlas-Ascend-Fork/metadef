# InputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:41:42.220Z pushedAt=2026-10-15T03:48:04.958Z -->

## Function

Sets the tensor description information, which is used to construct information such as **ComputeNodeInfo** in the base class **ExtendedKernelContext** of **KernelContext**.

## Function Prototype

```cpp
OpKernelContextBuilder &InputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the operator input instance.|
|dtype|Input|Data type of the input tensor.|
|origin_format|Input|Original format of the input tensor.|
|storage_format|Input|Storage format of the input tensor.|
|expand_dims_type|Input|Dimension expansion rule **ExpandDimsType** of the input tensor, defaulting to **{}**.|

## Return Value

Reference to the **OpKernelContextBuilder** object, which is used for chained calls.

## Constraints

This API must be called before the **Build** method; otherwise, the constructed **KernelContext** will contain undefined data.
