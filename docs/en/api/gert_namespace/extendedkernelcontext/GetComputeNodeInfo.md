# GetComputeNodeInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:55:05.941Z pushedAt=2026-10-15T03:48:04.882Z -->

## Function

Obtains the information of the compute node corresponding to this kernel.

During graph execution, the kernel of each node on the graph is executed. This method obtains the **ComputeNodeInfo** saved in **KernelContext**, and **ComputeNodeInfo** contains information such as **InputDesc**.

## Function Prototype

```cpp
const ComputeNodeInfo *GetComputeNodeInfo() const
```

## Parameters

None

## Return Value

Information of the compute node.

For the definition of **ComputeNodeInfo**, see [ComputeNodeInfo](../computenodeinfo/ComputeNodeInfo.md).

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
auto compute_node_info = extend_context->GetComputeNodeInfo();
```
