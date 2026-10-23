# MulOverflow

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:17:44.548Z pushedAt=2026-10-15T03:48:04.684Z -->

## Function

Checks whether multiplying two values causes an overflow, and returns the correct result when no overflow occurs.

## Function Prototype

**template<typename TLhs, typename TRhs, typename TRet\>**

**bool MulOverflow\(TLhs lhs, TRhs rhs, TRet &ret\)**

## Parameters

**Table 1** Template parameters

|Parameter|Description|
|--|--|
|**TLhs**|Data type of the left operand of the multiplication.|
|**TRhs**|Data type of the right operand of the multiplication.|
|**TRet**|Data type of the multiplication result.|

**Table 2** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**lhs**|Input|Left operand of the multiplication.|
|**rhs**|Input|Right operand of the multiplication.|
|**ret**|Input|Result of multiplying the left and right operands. This result is valid only when the function returns **true**.|

## Return Value

**true** indicates that the computation failed and the value of **ret** is invalid; **false** indicates that the computation succeeded and the value of **ret** is valid.

## Constraints

None

## Example

```cpp
ge::DataType out_data_type = ge::DT_FLOAT;
GE_ASSERT_GRAPH_SUCCESS(GetOutputDataType(context, out_data_type), "get data type failed");
GE_ASSERT_TRUE(out_data_type == ge::DataType::DT_INT32 || out_data_type == ge::DataType::DT_INT64,
               "only support DT_INT32 and DT_INT64, but out_data_type is %s",
               ge::TypeUtils::DataTypeToSerialString(out_data_type).c_str());
const auto is_malloc = (out_data_type == ge::DataType::DT_INT32);
const auto data_type_size = ge::GetSizeByDataType(out_data_type);
if (data_type_size <= 0) {
  // Report an error.
}
size_t malloc_buffer_size = 0U;
if (ge::MulOverflow(static_cast<size_t>(data_type_size), Shape::kMaxDimNum, malloc_buffer_size)) {
  // Report an error.
}
if (ge::AddOverflow(malloc_buffer_size, sizeof(GertTensorData), malloc_buffer_size)) {
  // Report an error.
}
```
