# GetDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:57:38.716Z pushedAt=2026-10-15T03:48:04.991Z -->

## Function

Obtains the **dim** value of the axis corresponding to **idx**.

## Function Prototype

```cpp
int64_t GetDim(const size_t idx) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|idx|Input|Index of **dim**. The caller must ensure that the index is valid.|

## Return Value

**dim** value. When **idx\** is greater than or equal to **kMaxDimNum**, \`kInvalidDimValue\` is returned. **kInvalidDimValue** indicates an invalid dimension value.

```cpp
int64_t kInvalidDimValue = -9223372036854775808;
```

## Constraints

The caller must ensure that the index is valid, that is, **idx** < **kMaxDimNum**.

## Example

```cpp
Shape shape0({3, 256, 256});
auto dim0 = shape0.GetDim(0); // 3
auto invalid_dim = shape0.GetDim(kMaxDimNum); // kInvalidDimValue
```
