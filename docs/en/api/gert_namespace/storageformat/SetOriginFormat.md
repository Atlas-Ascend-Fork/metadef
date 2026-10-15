# SetOriginFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:03:44.479Z pushedAt=2026-10-15T03:48:05.005Z -->

## Function

Sets the original format.

## Function Prototype

```cpp
void SetOriginFormat(const ge::Format origin_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**origin_format**|Input|Original format.|

## Return Value

None

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
format.SetOriginFormat(ge::Format::FORMAT_NC);
```
