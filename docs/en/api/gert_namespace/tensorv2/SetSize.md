# SetSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:32:30.256Z pushedAt=2026-10-15T03:48:05.070Z -->

## Function

Sets the memory size of a tensor.

## Function Prototype

```cpp
void SetSize(const size_t size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|size|Input|Memory size of the tensor, in bytes.|

## Return Value

None

## Constraints

None

## Example

```cpp
StorageShape sh({1, 2, 3}, {1, 2, 3});
TensorV2 t = {sh, {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}}, kOnHost, ge::DT_FLOAT, nullptr};
t.SetSize(0U);
```
