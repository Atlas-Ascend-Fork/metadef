# SetStorageFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:04:11.451Z pushedAt=2026-10-15T03:48:05.006Z -->

## Function

Sets the runtime format.

## Function Prototype

```cpp
void SetStorageFormat(const ge::Format storage_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|storage_format|Input|Runtime format.|

## Return Value

None

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
format.SetStorageFormat(ge::Format::FORMAT_NC);
```
