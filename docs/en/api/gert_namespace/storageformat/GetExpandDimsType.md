# GetExpandDimsType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:01:32.424Z pushedAt=2026-10-15T03:48:05.000Z -->

## Function

Obtains the dimension expansion rule.

## Function Prototype

```cpp
ExpandDimsType GetExpandDimsType() const
```

## Parameters

None

## Return Value

Dimension expansion rule.

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
auto fmt_dim_type = format.GetExpandDimsType();
```
