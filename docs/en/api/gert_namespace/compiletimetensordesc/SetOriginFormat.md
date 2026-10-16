# SetOriginFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:31:43.917Z pushedAt=2026-10-15T03:48:04.831Z -->

## Function

Sets the original data layout format of the tensor in **CompileTimeTensorDesc**.

## Function Prototype

```cpp
void SetOriginFormat(const ge::Format format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Original data layout format information to be set. For the definition of **ge::Format**, see **Format**.|

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
