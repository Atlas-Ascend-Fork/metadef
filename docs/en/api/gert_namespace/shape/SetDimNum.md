# SetDimNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:00:19.922Z pushedAt=2026-10-15T03:48:04.997Z -->

## Function

Sets the number of dimensions of a shape.

## Function Prototype

```cpp
void SetDimNum(const size_t dim_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|dim_num|Input|Sets the number of dimensions of a shape to **dim_num**.|

## Return Value

None

## Constraints

None

## Example

```cpp
Shape shape0({3, 256, 256});
shape0.SetDimNum(1);
auto dim_num = shape0.GetDimNum(); // 1
```
