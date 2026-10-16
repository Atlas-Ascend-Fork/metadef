# OutputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:36:58.311Z pushedAt=2026-10-15T03:48:04.949Z -->

## Function

Sets the output tensor description information, which is used to construct the **ComputeNodeInfo** information in the base class **ExtendedKernelContext** of **InferDataTypeContext**. There is no need to set the output data type information, because the output data type is inferred by the operator from the input data type.

## Function Prototype

```cpp
OpInferDataTypeContextBuilder &OutputTensorDesc(size_t index, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the operator output instance.|
|origin_format|Input|Original format of the output tensor.|
|storage_format|Input|Storage format of the output tensor.|
|expand_dims_type|Input|Dimension expansion rule **ExpandDimsType** of the output tensor. The default value is **{}**.|

## Return Value

Returns the **OpInferDataTypeContextBuilder** object, which is used for chained calls.

## Constraints

Before calling the **Build** method, this API must be called; otherwise, the constructed **InferDataTypeContext** will contain undefined data.
