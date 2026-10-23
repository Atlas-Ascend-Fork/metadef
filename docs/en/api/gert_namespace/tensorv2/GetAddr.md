# GetAddr

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:23:36.000Z pushedAt=2026-10-15T03:48:05.051Z -->

## Function

Obtains the data address of a tensor.

## Function Prototype

```cpp
const void *GetAddr() const
void *GetAddr()
```

## Parameters

None

## Return Value

Returns the data address.

## Constraints

None

## Example

```cpp
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                kFollowing,                                  // placement
                ge::DT_FLOAT16,                              //dt
                nullptr};
auto addr = tensor.GetAddr(); // &tensor + 1
```
