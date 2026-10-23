# SetStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:09:34.001Z pushedAt=2026-10-15T03:48:05.019Z -->

## Function

Sets the stride value of the specified **idx** axis.

## Function Prototype

```cpp
void SetStride(size_t idx, const int64_t stride)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|idx|Input|Index of the dimension. The caller must ensure that the index is valid.|
|stride|Input|Stride set for the **idx** axis.|

## Return Value

None

## Constraints

The caller must ensure that the index is valid.

## Example

```cpp
Stride stride0({3, 256, 256});
stride0.SetStride(0U, 1); // 1,256,256
```
