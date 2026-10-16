# GetPlacement

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:13:16.729Z pushedAt=2026-10-15T03:48:05.026Z -->

## Function

Obtains the placement of the tensor.

## Function Prototype

```cpp
TensorPlacement GetPlacement() const
```

## Parameters

None

## Return Value

Returns the placement of the tensor.

For the definition of the **TensorPlacement** type, see [TensorPlacement](../TensorPlacement.md).

## Constraints

None

## Example

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
              kFollowing,                                  // placement
              ge::DT_FLOAT16,                              //dt
              nullptr};
auto placement = tensor.GetPlacement(); // kFollowing
```
