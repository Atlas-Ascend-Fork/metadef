# GetInputsNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:33:39.760Z pushedAt=2026-10-15T03:48:04.836Z -->

## Function

Obtains the actual number of inputs of the operator in the network.

## Function Prototype

```cpp
size_t GetInputsNum() const
```

## Parameters

None

## Return Value

Actual number of inputs of the operator.

## Constraints

None

## Example

```cpp
size_t index = compute_node_info->GetInputsNum();
```
