# GetOutputTdInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:36:09.132Z pushedAt=2026-10-15T03:48:04.842Z -->

## Function

Obtains the tensor description of the specified output of the operator. Note that shape information that cannot be determined at compile time is not included in the tensor description (because the shape cannot be determined at compile time, the tensor description does not contain shape information).

## Function Prototype

```cpp
const CompileTimeTensorDesc *GetOutputTdInfo(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Output index of the operator, counting from 0.|

## Return Value

Returns the **const**-type tensor description.

## Constraints

None

## Example

```cpp
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto output_td = compute_node_info->GetOutputTdInfo(output_index);
```
