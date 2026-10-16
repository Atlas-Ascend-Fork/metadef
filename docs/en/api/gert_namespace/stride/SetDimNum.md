# SetDimNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:08:54.880Z pushedAt=2026-10-15T03:48:05.017Z -->

## Function

Sets the number of dimensions of the stride object.

## Function Prototype

```cpp
void SetDimNum(const size_t dim_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**dim_num**|Input|Sets the number of dimensions of the stride object to **dim_num**.|

## Return Value

None

## Constraints

None

## Example

```cpp
Stride stride0({3, 256, 256});
stride0.SetDimNum(1);
auto dim_num = stride0.GetDimNum(); // 1
```
