# GetShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:06:09.759Z pushedAt=2026-10-15T03:48:04.764Z -->

## Function

Obtains the shape of the tensor described by **TensorDesc**.

## Function Prototype

```cpp
Shape GetShape() const
```

## Parameters

None

## Return Value

[Shape](../shape/Shape.md) type: shape described by **TensorDesc**.

## Exception Handling

None

## Constraints

Because the returned **Shape** information is a value copy, modifying the returned **Shape** information does not affect the existing **Shape** information in **TensorDesc**.
