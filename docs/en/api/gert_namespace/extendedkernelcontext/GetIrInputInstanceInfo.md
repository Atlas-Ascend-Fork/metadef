# GetIrInputInstanceInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:57:18.248Z pushedAt=2026-10-15T03:48:04.886Z -->

## Function

Obtains the instantiation information of the corresponding input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const AnchorInstanceInfo *GetIrInputInstanceInfo (const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|

## Return Value

Instantiation information of the specified input.

For the definition of **AnchorInstanceInfo**, see [AnchorInstanceInfo](../anchorinstanceinfo/AnchorInstanceInfo.md).

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeInfo()->GetIrInputsNum(); ++idx) {
  auto input_td = extend_context->GetIrInputInstanceInfo(idx);
  ...
}
```
