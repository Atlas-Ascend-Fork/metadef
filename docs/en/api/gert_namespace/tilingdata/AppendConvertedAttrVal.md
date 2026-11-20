# AppendConvertedAttrVal

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:56:48.645Z pushedAt=2026-10-15T03:48:05.112Z -->

## Function

Converts the **index**-th attribute in the **RuntimeAttrs** memory from the **src\_type** data type to the **dst\_type** data type, and appends it to the end of the current **tilingdata**.

## Function Prototype

```cpp
ge::graphStatus AppendConvertedAttrVal(const RuntimeAttrs *attrs, const size_t attr_index, const AttrDataType src_type, const AttrDataType dst_type)
```

## Parameters

**Table 1**  Parameter List

|Parameter|Input/Output|Description|
|--|--|--|
|attrs|Input|Attributes during graph execution.|
|attr_index|Input|Index of the attribute.|
|src_type|Input|Original dtype of the attribute. Type **AttrDataType**. For the definition of **AttrDataType**, see [AttrDataType](../AttrDataType.md). The supported value ranges and mapping between **src_type** and **dst_type** are listed in Table 2.|
|dst_type|Input|Target dtype of the attribute. The supported value ranges and mapping between **src_type** and **dst_type** are listed in Table 2.|

**Table 2**  Supported value ranges and mapping between **src\_type** and **dst\_type**

|src_type|dst_type|
|--|--|
|kBool|kBool, kFloat16, kBfloat16, kFloat32, kInt8, kInt16, kInt32, kInt64, kUint8, kUint16, kUint32, kUint64|
|kListBool|kListBool, kListFloat16, kListBfloat16, kListFloat32, kListInt8, kListInt16, kListInt32, kListInt64, kListUint8, kListUint16, kListUint32, kListUint64|
|kFloat32|kBool, kFloat16, kBfloat16, kFloat32, kInt8, kInt16, kInt32, kInt64, kUint8, kUint16, kUint32, kUint64|
|kListFloat32|kListBool, kListFloat16, kListBfloat16, kListFloat32, kListInt8, kListInt16, kListInt32, kListInt64, kListUint8, kListUint16, kListUint32, kListUint64|
|kListListFloat32|kListListBool, kListListFloat16, kListListBfloat16, kListListFloat32, kListListInt8, kListListInt16, kListListInt32, kListListInt64, kListListUint8, kListListUint16, kListListUint32, kListListUint64|
|kInt32|kBool, kFloat16, kBfloat16, kFloat32, kInt8, kInt16, kInt32, kInt64, kUint8, kUint16, kUint32, kUint64|
|kListInt32|kListBool, kListFloat16, kListBfloat16, kListFloat32, kListInt8, kListInt16, kListInt32, kListInt64, kListUint8, kListUint16, kListUint32, kListUint64|
|kListListInt32|kListListBool, kListListFloat16, kListListBfloat16, kListListFloat32, kListListInt8, kListListInt16, kListListInt32, kListListInt64, kListListUint8, kListListUint16, kListListUint32, kListListUint64|
|kInt64|kBool, kFloat16, kBfloat16, kFloat32, kInt8, kInt16, kInt32, kInt64, kUint8, kUint16, kUint32, kUint64|
|kListInt64|kListBool, kListFloat16, kListBfloat16, kListFloat32, kListInt8, kListInt16, kListInt32, kListInt64, kListUint8, kListUint16, kListUint32, kListUint64|
|kListListInt64|kListListBool, kListListFloat16, kListListBfloat16, kListListFloat32, kListListInt8, kListListInt16, kListListInt32, kListListInt64, kListListUint8, kListListUint16, kListListUint32, kListListUint64|
|kString|kString|

## Return Value

- Returns **ge::GRAPH\_SUCCESS** on success.
- Returns **ge::GRAPH\_FAILED** on failure.

## Constraints

None

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());

auto holder = BuildTestContext();
auto context = holder.GetContext<TilingContext>();
auto ret = td->AppendConvertedAttrVal(context->GetAttrs(), 1, AttrDataType::kString, AttrDataType::kString)


FakeKernelContextHolder BuildTestContext() {
  auto holder = gert::KernelRunContextFaker()
                    .NodeIoNum(1, 1)
                    .IrInputNum(1)
                    .NodeInputTd(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_ND)
                    .NodeOutputTd(0, ge::DT_FLOAT16, ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ)
                    .NodeAttrs({{"int", ge::AnyValue::CreateFrom<int64_t>(0x7fffffffUL)},
                                {"str", ge::AnyValue::CreateFrom<std::string>("Hello!")},
                                {"bool", ge::AnyValue::CreateFrom<bool>(true)},
                                {"float", ge::AnyValue::CreateFrom<float>(10.101)},
                                {"list_int", ge::AnyValue::CreateFrom<std::vector<int64_t>>({1, 2, 3})},
                                {"list_int2", ge::AnyValue::CreateFrom<std::vector<int64_t>>({4, 5, 6})},
                                {"list_float", ge::AnyValue::CreateFrom<std::vector<float>>({1.2, 3.4, 4.5})}})
                    .Build();
  return holder;
}
```
