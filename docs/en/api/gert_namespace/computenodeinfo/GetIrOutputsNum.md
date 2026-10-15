# GetIrOutputsNum

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:34:25.790Z pushedAt=2026-10-15T03:48:04.838Z -->

## Function

Obtains the number of outputs in the operator IR prototype definition.

## Function Prototype

```cpp
size_t GetIrOutputsNum() const
```

## Parameters

None

## Return Value

Number of outputs defined in the IR prototype, which is of the **size\_t** type.

## Constraints

None

## Example

```cpp
size_t index = compute_node_info->GetIrOutputsNum();
```
