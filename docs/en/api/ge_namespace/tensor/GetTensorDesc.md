# GetTensorDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:55:40.513Z pushedAt=2026-10-15T03:48:04.748Z -->

## Function

Obtains the descriptor of a tensor.

## Function Prototype

```cpp
TensorDesc GetTensorDesc() const
```

## Parameters

None

## Return Value

Returns the descriptor of the current tensor, which is of the [TensorDesc](../tensordesc/TensorDesc.md) type.

## Exception Handling

None

## Constraints

Modifying the returned **TensorDesc** information does not affect the existing **TensorDesc** information in the **Tensor** object.
