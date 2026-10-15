# OutputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:38:37.163Z pushedAt=2026-10-15T03:48:04.952Z -->

## Function

Sets the tensor description information of the operator output, which is used to construct information such as **ComputeNodeInfo** in **ExtendedKernelContext**, the base class of **InferShapeContext**.

## Function Prototype

```cpp
OpInferShapeContextBuilder &OutputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the output, corresponding to the output instance index of the operator.|
|dtype|Input|Data type of the output tensor.|
|origin_format|Input|Original format of the output tensor.|
|storage_format|Input|Storage format of the output tensor.|
|expand_dims_type|Input|Dimension expansion rule **ExpandDimsType** of the output tensor.|

## Return Value

**OpInferShapeContextBuilder** object, which is used for chained calls.

## Constraints

Before calling the **Build** method, this API must be called; otherwise, the constructed **InferShapeContext** will contain undefined data.
