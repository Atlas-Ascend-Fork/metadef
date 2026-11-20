# GetShapeSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:49:33.055Z pushedAt=2026-10-15T03:48:04.738Z -->

## Function

Obtains the product of all **dim**s in the shape. Scalar and exceptional cases
are described in the return value.

## Function Prototype

```cpp
int64_t GetShapeSize() const
```

## Parameters

None

## Return Value

Returns the product of all **dim**s, with these special cases:

- If any dimension is `-1` (`ge::UNKNOWN_DIM`) or `-2`
  (`ge::UNKNOWN_DIM_NUM`), returns `-1` to indicate an unknown shape.
- If any dimension is `0`, returns `0` to indicate an empty tensor.
- If the shape has no dimensions, returns `0` to indicate a scalar.
- If multiplying the dimensions overflows `int64_t`, returns `0`.
- Otherwise, returns the product of all dimensions.

## Exception Handling

None

## Constraints

None
