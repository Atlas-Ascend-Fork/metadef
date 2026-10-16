# OutputTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:50:10.403Z pushedAt=2026-10-15T03:48:04.976Z -->

## Function

Sets the output tensor description, which is used to construct information such as **ComputeNodeInfo** in **ExtendedKernelContext**, the base class of **TilingParseContext**.

## Function Prototype

```cpp
OpTilingParseContextBuilder &OutputTensorDesc(size_t index, ge::DataType dtype, ge::Format origin_format, ge::Format storage_format, const gert::ExpandDimsType &expand_dims_type = {})
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index of the operator output instance.|
|dtype|Input|Data type of the output tensor.|
|origin_format|Input|Original format of the output tensor.|
|storage_format|Input|Storage format of the output tensor.|
|expand_dims_type|Input|Dimension expansion rule **ExpandDimsType** of the output tensor, defaulting to **{}**.|

## Return Value

**OpTilingParseContextBuilder** object, which is used for chained calls.

## Constraints

Before calling the **Build** method, you must call this API; otherwise, the constructed **TilingParserContext** will contain undefined data.
