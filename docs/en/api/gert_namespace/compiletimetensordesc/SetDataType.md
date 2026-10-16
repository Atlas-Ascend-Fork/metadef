# SetDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:30:45.167Z pushedAt=2026-10-15T03:48:04.829Z -->

## Function

Sets the data type of the tensor in **CompileTimeTensorDesc**.

## Function Prototype

```cpp
void SetDataType(const ge::DataType data_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data_type|Input|Data type information of the tensor described by **CompileTimeTensorDesc** to be set. For details about the **ge::DataType** type, see **DataType**.|

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
