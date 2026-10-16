# InputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:35:23.534Z pushedAt=2026-10-15T03:48:04.946Z -->

## Function

Sets the description of the input tensor to construct **ComputeNodeInfo** in the base class **ExtendedKernelContext** of **InferDataTypeContext**.

## Function Prototype

```cpp
OpInferDataTypeContextBuilder &InputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
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

Returns a reference to the **OpInferDataTypeContextBuilder** object for chained calls.

## Constraints

Before calling the **Build** method, you must call this API; otherwise, the constructed **InferDataTypeContext** will contain undefined data.
