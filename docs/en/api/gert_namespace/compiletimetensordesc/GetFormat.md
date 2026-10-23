# GetFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:29:16.530Z pushedAt=2026-10-15T03:48:04.825Z -->

## Function

Obtains the data layout format of the compile-time tensor.

## Function Prototype

```cpp
const StorageFormat &GetFormat() const
```

## Parameters

None

## Return Value

Returns the data layout format. [StorageFormat](../storageformat/StorageFormat.md) type, including the original format and storage format.

## Constraints

None

## Example

```cpp
StorageFormat storageFormat(ge::Format::FORMAT_NC, ge::FORMAT_NCHW, {});
gert::CompileTimeTensorDesc compileTimeTensorDesc;
compileTimeTensorDesc.SetStorageFormat(storageFormat.GetStorageFormat());
auto storage_fmt = compileTimeTensorDesc.GetFormat(); // ge::FORMAT_NCHW
compileTimeTensorDesc.SetOriginFormat(storageFormat.GetOriginFormat());
auto origin_fmt = compileTimeTensorDesc.GetOriginFormat(); // ge::Format::FORMAT_NC
```
