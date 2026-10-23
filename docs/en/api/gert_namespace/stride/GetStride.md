# GetStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:07:41.716Z pushedAt=2026-10-15T03:48:05.015Z -->

## Function

Obtains the stride value of the axis corresponding to **idx**.

## Function Prototype

```cpp
int64_t GetStride(const size_t idx) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**idx**|Input|Dimension index. The caller must ensure that the index is valid.|

## Return Value

Stride value. When **idx** \>= **kMaxDimNum**, \`kInvalidStrideValue\` is returned.

## Constraints

The caller must ensure that **idx** is valid, that is, **idx** < **kMaxDimNum**.

## Example

```cpp
Stride stride({3, 256, 256});
auto stride0 = stride.GetStride(0); // 3
auto invalid_stride = stride.GetStride(Stride::kMaxDimNum); // kInvalidStrideValue
```
