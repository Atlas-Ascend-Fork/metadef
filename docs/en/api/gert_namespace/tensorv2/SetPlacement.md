# SetPlacement

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:32:15.451Z pushedAt=2026-10-15T03:48:05.069Z -->

## Function

Sets the placement of a tensor.

## Function Prototype

```cpp
void SetPlacement(const TensorPlacement placement)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|placement|Input|Placement of the tensor to be set. For the definition of the **TensorPlacement** type, see **TensorPlacement**.|

## Return Value

None

## Constraints

None

## Example

```cpp
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                kFollowing,                                  // placement
                ge::DT_FLOAT16,                              //dt
                nullptr};
tensor.SetPlacement(TensorPlacement::kOnHost);
auto placement = tensor.GetPlacement();
```
