# GetStorageFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:02:24.719Z pushedAt=2026-10-15T03:48:05.001Z -->

## Function

Obtains the runtime format.

## Function Prototype

```cpp
ge::Format GetStorageFormat() const
```

## Parameters

None

## Return Value

Runtime format.

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
auto storage_format = format.GetStorageFormat();  // Format::FORMAT_C1HWNC0
```
