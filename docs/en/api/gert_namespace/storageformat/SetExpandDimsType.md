# SetExpandDimsType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:03:41.261Z pushedAt=2026-10-15T03:48:05.004Z -->

## Function

Sets the dimension expansion rule.

## Function Prototype

```cpp
void SetExpandDimsType(const ExpandDimsType &expand_dims_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**expand_dims_type**|Input|Dimension expansion rule.|

## Return Value

None

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
ExpandDimsType new_dim_type("1010");
format.SetExpandDimsType(new_dim_type);
```
