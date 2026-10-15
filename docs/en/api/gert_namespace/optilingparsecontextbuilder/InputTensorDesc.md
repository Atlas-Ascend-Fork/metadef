# InputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:48:56.436Z pushedAt=2026-10-15T03:48:04.973Z -->

## Function

Sets the tensor description information, which is used to construct information such as **ComputeNodeInfo** in **ExtendedKernelContext**, the base class of **TilingParseContext**.

## Function Prototype

```cpp
OpTilingParseContextBuilder &InputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the operator input instance.|
|dtype|Input|Data type of the input tensor.|
|origin_format|Input|Original format of the input tensor.|
|storage_format|Input|Storage format of the input tensor.|
|expand_dims_type|Input|Dimension expansion rule **ExpandDimsType** of the input tensor. The default value is **{}**.|

## Return Value

**OpTilingParseContextBuilder** object, which is used for chained calls.

## Constraints

Before calling the **Build** method, you must call **InputTensorDesc** to set the tensor description information; otherwise, the constructed **TilingParserContext** will contain undefined data.
