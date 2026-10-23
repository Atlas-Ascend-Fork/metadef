# GetInputDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:57:12.745Z pushedAt=2026-10-15T03:48:04.885Z -->

## Function

Obtains the tensor description of the corresponding input based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
const CompileTimeTensorDesc *GetInputDesc(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Pointer to the input **TensorDesc**. If the input **index** is invalid, a null pointer is returned.

For the definition of **CompileTimeTensorDesc**, see [CompileTimeTensorDesc](../compiletimetensordesc/CompileTimeTensorDesc.md).

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeInputNum(); ++idx) {
  auto input_td = extend_context->GetInputDesc(idx);
  ...
}
```
