# OutputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:40:45.347Z pushedAt=2026-10-15T03:48:04.956Z -->

## Function

Sets the tensor description information of the operator output, which is used to construct the **ComputeNodeInfo** information in **ExtendedKernelContext**, the base class of **InferShapeRangeContext**.

## Function Prototype

```cpp
OpInferShapeRangeContextBuilder &OutputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the operator output instance.|
|origin_format|Input|Original format of the output tensor.|
|storage_format|Input|Storage format of the output tensor.|
|expand_dims_type|Input|Dimension expansion rule **ExpandDimsType** of the output tensor, defaulting to **{}**.|

## Return Value

**OpInferShapeRangeContextBuilder** object, which is used for chained calls.

## Constraints

Before calling the **Build** method, you must call this API; otherwise, the constructed **InferShapeRangeContext** will contain undefined data.
