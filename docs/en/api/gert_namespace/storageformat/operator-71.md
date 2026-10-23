# operator==

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:03:18.210Z pushedAt=2026-10-15T03:48:05.003Z -->

## Function

Checks whether the formats are the same.

## Function Prototype

```cpp
bool operator==(const StorageFormat &other) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|other|Input|Another format.|

## Return Value

**true** indicates that the formats are the same, and **false** indicates that the formats are different.

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
StorageFormat another_format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_NC, dim_type);
bool is_same_fmt = format == another_format; // false
```
