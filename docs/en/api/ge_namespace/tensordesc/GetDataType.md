# GetDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:02:25.025Z pushedAt=2026-10-15T03:48:04.758Z -->

## Function

Obtains the data type of the tensor described by **TensorDesc**.

## Function Prototype

```cpp
DataType GetDataType() const
```

## Parameters

None

## Return Value

[DataType](../DataType.md) type, which is the data type of the tensor described by **TensorDesc**.

## Exception Handling

None

## Constraints

Because the returned **DataType** information is a value copy, modifying the returned **DataType** information does not affect the existing **DataType** information in **TensorDesc**.
