# MutableExpandDimsType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:02:51.061Z pushedAt=2026-10-15T03:48:05.003Z -->

## Function

Obtains the writable dimension expansion rule.

## Function Prototype

```cpp
ExpandDimsType &MutableExpandDimsType()
```

## Parameters

None

## Return Value

Reference to the dimension expansion rule.

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
ExpandDimsType new_dim_type("1010");
format.SetExpandDimsType(new_dim_type);
auto &fmt_dim_type = format.MutableExpandDimsType();
```
