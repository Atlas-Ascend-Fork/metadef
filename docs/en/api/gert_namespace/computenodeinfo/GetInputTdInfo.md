# GetInputTdInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:33:55.704Z pushedAt=2026-10-15T03:48:04.836Z -->

## Function

Obtains the corresponding input tensor descriptor of the operator based on the input index. Note that shape information that cannot be determined at compile time is not included in the tensor descriptor (because the shape cannot be determined at compile time, this tensor descriptor does not contain shape information).

## Function Prototype

```cpp
const CompileTimeTensorDesc *GetInputTdInfo(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Input index of the operator, counted from 0.|

## Return Value

Returns the tensor descriptor information of the **const** type.

## Constraints

None

## Example

```cpp
auto compute_node_info = extend_kernel_context->GetComputeNodeInfo();
auto input_td = compute_node_info->GetInputTdInfo(input_index);
```
