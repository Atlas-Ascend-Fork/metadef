# SetExpandDimsType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:31:16.818Z pushedAt=2026-10-15T03:48:04.831Z -->

## Function

Sets the dimension expansion rule used when converting the original format to the runtime format.

## Function Prototype

```cpp
void SetExpandDimsType(const ExpandDimsType &expand_dims_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|expand_dims_type|Input|Dimension expansion rule to be set. For details about **ExpandDimsType**, see **ExpandDimsType**.|

## Return Value

None

## Constraints

None

## Example

```cpp
auto dtype_ = ge::DataType::DT_INT32;
StorageFormat fmt_(ge::Format::FORMAT_NC, ge::FORMAT_NCHW, {});
ExpandDimsType type_("1001");
gert::CompileTimeTensorDesc td;
td.SetDataType(dtype_);
auto dtype = td.GetDataType(); // ge::DataType::DT_INT32;
td.SetStorageFormat(fmt_.GetStorageFormat());
auto storage_fmt = td.GetStorageFormat(); // ge::FORMAT_NCHW
td.SetOriginFormat(fmt_.GetOriginFormat());
auto origin_fmt = td.GetOriginFormat(); // ge::Format::FORMAT_NC
td.SetExpandDimsType(type_);
auto type = td.GetExpandDimsType(); // type_("1001")
```
