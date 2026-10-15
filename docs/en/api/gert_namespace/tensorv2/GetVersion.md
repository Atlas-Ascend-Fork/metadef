# GetVersion

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:28:40.052Z pushedAt=2026-10-15T03:48:05.061Z -->

## Function

Obtains the version in a tensor.

## Function Prototype

```cpp
TensorVersion GetVersion () const
```

## Parameters

None

## Return Value

Returns the version of a tensor.

For the definition of the **TensorVersion** type, see [TensorVersion](../TensorVersion.md).

## Constraints

None

## Example

```cpp
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                kFollowing,                                  // placement
                ge::DT_FLOAT16,                              //dt
                nullptr};
auto version = tensor.GetVersion(); // kTensorV2
```
