# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:01:21.256Z pushedAt=2026-10-15T03:48:04.999Z -->

## Function

Constructs a format that includes the original format, runtime format, and dimension expansion rule.

## Function Prototype

```cpp
StorageFormat()
StorageFormat(const ge::Format origin_format, const ge::Format storage_format, const ExpandDimsType &expand_dims_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|origin_format|Input|Original format.|
|storage_format|Input|Runtime format.|
|expand_dims_type|Input|Dimension expansion rule.|

## Return Value

Returns a **StorageFormat** object with specified **origin\_format**, **storage\_format**, and **expand\_dims\_type**.

## Constraints

None

## Example

```cpp
ExpandDimsType dim_type("1100");
StorageFormat format(ge::Format::FORMAT_NCHW, ge::Format::FORMAT_C1HWNC0, dim_type);
```
