# GetIrOutputInstanceInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:57:50.238Z pushedAt=2026-10-15T03:48:04.887Z -->

## Function

Obtains the instantiation information of the corresponding output based on the output index in the operator IR prototype definition.

## Function Prototype

```cpp
const AnchorInstanceInfo *GetIrOutputInstanceInfo(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Output index in the operator IR prototype definition, counted from 0.|

## Return Value

Instantiation information of the specified input.

For the definition of **AnchorInstanceInfo**, see [AnchorInstanceInfo](../anchorinstanceinfo/AnchorInstanceInfo.md).

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeInfo()->GetOutputsNum(); ++idx) {
  auto output_td = extend_context->GetIrOutputInstanceInfo(idx);
  ...
}
```
