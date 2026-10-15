# GetOutputsNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:35:51.059Z pushedAt=2026-10-15T03:48:04.840Z -->

## Function

Obtains the actual number of outputs of the operator in the network.

## Function Prototype

```cpp
size_t GetOutputsNum() const
```

## Parameters

None

## Return Value

Actual number of outputs of the operator.

## Constraints

None

## Example

```cpp
size_t index = compute_node_info->GetOutputsNum();
```
