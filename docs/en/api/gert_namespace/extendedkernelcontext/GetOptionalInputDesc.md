# GetOptionalInputDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:59:53.703Z pushedAt=2026-10-15T03:48:04.890Z -->

## Function

Obtains the tensor description of the corresponding optional input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const CompileTimeTensorDesc *GetOptionalInputDesc(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|

## Return Value

Pointer to the input **TensorDesc**. A null pointer is returned when the input index is invalid or when the input is not instantiated.

For the definition of **CompileTimeTensorDesc**, see [CompileTimeTensorDesc](../compiletimetensordesc/CompileTimeTensorDesc.md).

## Constraints

None

## Example

```cpp
// Assume that KernelContext *context already exists.
auto extend_context = reinterpret_cast<ExtendedKernelContext *>(context);
// Case 1: Assume that the 0th input of an operator's IR prototype is an optional input, and there is actually 1 input.
auto optional_input_td = extend_context->GetOptionalInputDesc(0); // Obtain the tensor description of the 0th optional input.
// Case 2: Assume that the 0th input of an operator's IR prototype is an optional input, and there is actually no input.
auto optional_input_td = extend_context->GetOptionalInputDesc(0); // nullptr
```
