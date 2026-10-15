# SetExpandDimsType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:18:00.490Z pushedAt=2026-10-15T03:48:05.037Z -->

## Function

Sets the dimension expansion rule of the shape.

## Function Prototype

```cpp
void SetExpandDimsType(const ExpandDimsType &expand_dims_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|expand_dims_type|Input|Dimension expansion rule to be set. For the definition of the **ExpandDimsType** type, see **ExpandDimsType**.|

## Return Value

None

## Constraints

None

## Example

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
              kFollowing,                                  // placement
              ge::DT_FLOAT16,                              //dt
              nullptr};
ExpandDimsType type("1001");
tensor.SetExpandDimsType(type);
auto expand_dims_type = tensor.GetExpandDimsType();   // type
```
