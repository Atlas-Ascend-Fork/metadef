# GetNodeName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:34:41.271Z pushedAt=2026-10-15T03:48:04.838Z -->

## Function

Obtains the name of the operator.

## Function Prototype

```cpp
const ge::char_t *GetNodeName() const
```

## Parameters

None

## Return Value

Returns the name of the operator.

## Constraints

None

## Example

```cpp
auto node_name = compute_node_info.GetNodeName();
```
