# GetOriginFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:01:50.488Z pushedAt=2026-10-15T03:48:05.001Z -->

## Function

Obtains the original format.

## Function Prototype

```cpp
ge::Format GetOriginFormat() const
```

## Parameters

None

## Return Value

Original format.

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
auto origin_format = format.GetOriginFormat();  // Format::FORMAT_NCHW
```
