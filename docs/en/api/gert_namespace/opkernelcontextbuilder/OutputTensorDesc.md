# OutputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:42:56.646Z pushedAt=2026-10-15T03:48:04.961Z -->

## Function

Sets the tensor description information, which is used to construct the **ComputeNodeInfo** information in the base class **ExtendedKernelContext** of **KernelContext**.

## Function Prototype

```cpp
OpKernelContextBuilder &OutputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input instance index.|
|dtype|Input|Data type of the output tensor.|
|origin_format|Input|Original format of the output tensor.|
|storage_format|Input|Storage format of the output tensor.|
|expand_dims_type|Input|Dimension expansion rule **ExpandDimsType** of the output tensor, defaulting to **{}**.|

## Return Value

Returns a reference to the **OpKernelContextBuilder** object for chained calls.

## Constraints

This API must be called before calling the **Build** method; otherwise, the constructed **KernelContext** will contain undefined data.
