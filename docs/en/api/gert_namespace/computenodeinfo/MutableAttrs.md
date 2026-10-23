# MutableAttrs

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:36:51.945Z pushedAt=2026-10-15T03:48:04.844Z -->

## Function

Obtains the attribute values of an operator. Only the attribute values registered in the operator IR prototype definition and the **IMPL\_OP** macro are returned; other attribute values are discarded.

The difference between this method and [GetAttrs](GetAttrs.md) is that it can return a non-**const** attribute object.

## Function Prototype

```cpp
RuntimeAttrs *MutableAttrs() const
```

## Parameters

None

## Return Value

All attribute values defined in the IR prototype and those registered through the **IMPL\_OP** macro. The attribute values are stored in the order defined by the IR prototype. The returned object is non-**const**.

## Constraints

None

## Example

```cpp
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto attrs = compute_node_info->MutableAttrs();
```
