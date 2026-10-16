# SetDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:59:32.001Z pushedAt=2026-10-15T03:48:04.996Z -->

## Function

Sets the dimension value of a specific axis.

## Function Prototype

```cpp
void SetDim(size_t idx, const int64_t dim_value)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|idx|Input|Index of **dim**. Callers must ensure that the index is valid.|
|dim_value|Input|Dimension value to set for the axis specified by **idx**.|

## Return Value

None

## Constraints

Callers must ensure that the index is valid.

## Example

```cpp
Shape shape0({3, 256, 256});
shape0.SetDim(0U, 1); // 1,256,256
```
