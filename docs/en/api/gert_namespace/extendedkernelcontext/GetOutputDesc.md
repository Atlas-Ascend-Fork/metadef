# GetOutputDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:00:39.972Z pushedAt=2026-10-15T03:48:04.890Z -->

## Function

Obtains the tensor description of the corresponding output based on the operator output index. The output index here refers to the actual index after operator instantiation, not the index in the prototype definition.

## Function Prototype

```cpp
const CompileTimeTensorDesc *GetOutputDesc(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index, counting from 0.|

## Return Value

Pointer to the output **TensorDesc**. If the input **index** is invalid, a null pointer is returned.

For the definition of **CompileTimeTensorDesc**, see [CompileTimeTensorDesc](../compiletimetensordesc/CompileTimeTensorDesc.md).

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
for (size_t idx = 0; idx < extend_context->GetComputeNodeInfo()->GetOutputsNum(); ++idx) {
  auto output_td = extend_context->GetOutputDesc(idx);
  ...
}
```
