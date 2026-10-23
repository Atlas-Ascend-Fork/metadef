# GetAttrs

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:32:54.267Z pushedAt=2026-10-15T03:48:04.835Z -->

## Function

Obtains the attribute values of an operator.

## Function Prototype

```cpp
const RuntimeAttrs *GetAttrs() const
```

## Parameters

None

## Return Value

Attribute values defined by all IR prototypes, which are **const** objects of type **RuntimeAttrs**. The attribute values are stored in the order defined by the IR prototypes.

## Constraints

None

## Example

```cpp
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto attrs = compute_node_info->GetAttrs();
```
