# GetNodeType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:35:15.275Z pushedAt=2026-10-15T03:48:04.839Z -->

## Function

Obtains the type of the operator.

## Function Prototype

```cpp
const ge::char_t *GetNodeType() const
```

## Parameters

None

## Return Value

Type of the operator.

## Constraints

None

## Example

```cpp
auto node_type = compute_node_info.GetNodeType();
```
