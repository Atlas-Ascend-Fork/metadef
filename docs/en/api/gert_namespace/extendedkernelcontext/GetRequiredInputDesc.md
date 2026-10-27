# GetRequiredInputDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:00:46.145Z pushedAt=2026-10-15T03:48:04.891Z -->

## Function

Obtains the tensor description of the corresponding required input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const CompileTimeTensorDesc *GetRequiredInputDesc(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counting from 0.|

## Return Value

**CompileTimeTensorDesc** pointer. A null pointer is returned when **index** is invalid or the input is not instantiated.

For the definition of **CompileTimeTensorDesc**, see [CompileTimeTensorDesc](../compiletimetensordesc/CompileTimeTensorDesc.md).

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
// Assume that the 0th input of the operator's IR prototype is a normal input, and there is actually one input.
auto required_input_td = extend_context->GetRequiredInputDesc(0); // Obtain the tensor description of the 0th input.
```
