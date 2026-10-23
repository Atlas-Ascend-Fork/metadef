# GetExpandDimsType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:24:36.430Z pushedAt=2026-10-15T03:48:05.053Z -->

## Function

Obtains the dimension expansion rule of the shape.

## Function Prototype

```cpp
ExpandDimsType GetExpandDimsType() const
```

## Parameters

None

## Return Value

Returns the dimension expansion rule of the shape.

For the definition of the **ExpandDimsType** type, see [ExpandDimsType](../expanddimstype/ExpandDimsType.md).

## Constraints

None

## Example

```cpp
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                kFollowing,                                  // placement
                ge::DT_FLOAT16,                              //dt
                nullptr};
auto expand_dims_type = tensor.GetExpandDimsType();   // ExpandDimsType{}
```
