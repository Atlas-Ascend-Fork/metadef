# operator\[\]

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:08:51.638Z pushedAt=2026-10-15T03:48:05.018Z -->

## Function

Obtains the stride value of the specified **idx** axis.

## Function Prototype

```cpp
const int64_t &operator[](const size_t idx) const
int64_t &operator[](const size_t idx)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|idx|Input|Dimension index. The caller must ensure that the index is valid.|

## Return Value

- **const int64\_t &operator\[\]\(const size\_t idx\) const**: stride value. The behavior is undefined when **idx** \>= **kMaxDimNum**.
- **int64\_t &operator\[\]\(const size\_t idx\)**: **dim** value. The behavior is undefined when **idx** \>= **kMaxDimNum**.

## Constraints

The caller must ensure that the index is valid, that is, **idx** < **kMaxDimNum**.

## Example

```cpp
Stride stride({3, 256, 256});
auto str0 = stride[0]; // 3
auto str5 = stride[5]; // 0
auto invalid_str = stride[Stride::kMaxDimNum]; // undefined behavior
```
