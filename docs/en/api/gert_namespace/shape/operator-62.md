# operator\[\]

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:59:29.493Z pushedAt=2026-10-15T03:48:04.996Z -->

## Function

Obtains the **dim** value of the specified **index** axis.

## Function Prototype

```cpp
const int64_t &operator[](const size_t idx) const
int64_t &operator[](const size_t idx)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|idx|Input|Index of **dim**. The caller must ensure that the index is valid.|

## Return Value

- **const int64\_t &operator\[\]\(const size\_t idx\) const**: **dim** value. The behavior is undefined when **idx** \>= **kMaxDimNum**.
- **int64\_t &operator\[\]\(const size\_t idx\)**: **dim** value. The behavior is undefined when **idx** \>= **kMaxDimNum**.

## Constraints

The caller must ensure that the index is valid, that is, **idx** < **kMaxDimNum**.

## Example

```cpp
Shape shape0({3, 256, 256});
auto dim0 = shape0[0]; // 3
auto dim5 = shape0[5]; // 0
auto invalid_dim = shape0[kMaxDimNum]; // The behavior is undefined.
```
