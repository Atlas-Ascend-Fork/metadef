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
|kInt64|kInt32, kUint32|
|kListInt64|kListInt32, kListUint32|
|kInt32|kInt32|
|kListInt32|kListInt32|
|kFloat32|kFloat32, kFloat16, kBfloat16, kInt64, kInt32, kInt16, kInt8|
|kListFloat32|kListFloat32, kListFloat16, kListInt64, kListInt32, kListInt16, kListInt8|
|kBool|kBool|
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
