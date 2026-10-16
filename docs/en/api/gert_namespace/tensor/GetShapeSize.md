# GetShapeSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:13:53.211Z pushedAt=2026-10-15T03:48:05.027Z -->

## Function

Obtains the shape size of the current tensor at runtime, that is, the number of elements contained in this tensor.

## Function Prototype

```cpp
int64_t GetShapeSize() const
```

## Parameters

None

## Return Value

Returns the shape size at runtime.

## Constraints

None

## Example

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
              kFollowing,                                  // placement
              ge::DT_FLOAT16,                              //dt
              nullptr};
auto shape_size = tensor.GetShapeSize(); // 16*3*224*224
```
