# GetVersion

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:15:29.106Z pushedAt=2026-10-15T03:48:05.032Z -->

## Function

Obtains the version in a tensor. **kTensorV1**: does not carry **view** and **offset** information. **kTensorV2**: carries **view** and **offset** information.

> [!NOTE] Note
> This API is a reserved API, retained for future functionality, and is not supported in the current version.

## Function Prototype

```cpp
TensorVersion GetVersion () const
```

## Parameters

None

## Return Value

Tensor version.

For the definition of the **TensorVersion** type, see [TensorVersion](../TensorVersion.md).

## Constraints

None

## Example

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
               {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
               kFollowing,                                  // placement
               ge::DT_FLOAT16,                              //dt
               nullptr};
auto version = tensor.GetVersion(); // kTensorV1
```
