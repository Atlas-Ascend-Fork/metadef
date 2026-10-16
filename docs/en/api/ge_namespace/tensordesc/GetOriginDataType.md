# GetOriginDataType

<!-- md-trans-meta sourceCommit=3546dd3f154857d3da51573eb7cca3d0cb68702a translatedAt=2026-10-09T02:03:38.998Z pushedAt=2026-10-15T03:48:04.760Z -->

## Function

Obtains the original **DataType** of the tensor in **TensorDesc**.

## Function Prototype

```cpp
DataType GetOriginDataType() const
```

## Parameters

None

## Return Value

[DataType](../DataType.md) type: original data type of the Tensor described by **TensorDesc**.

## Exception Handling

Because the returned **DataType** information is a value copy, modifying the returned **DataType** information does not affect the existing **DataType** information in **TensorDesc**.

## Constraints

None
