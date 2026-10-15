# GetDynamicInputDesc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:56:21.656Z pushedAt=2026-10-15T03:48:04.884Z -->

## Function

Obtains the tensor description information of the corresponding dynamic input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const CompileTimeTensorDesc *GetDynamicInputDesc(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|
|relative_index|Input|Relative index of this input after instantiation. For example, if a **DYNAMIC_INPUT** is instantiated into 3 inputs, the valid range of **relative_index** is [0,2].|

## Return Value

**CompileTimeTensorDesc** pointer. A null pointer is returned when **index** or **relative\_index** is invalid.

For the definition of **CompileTimeTensorDesc**, see [CompileTimeTensorDesc](../compiletimetensordesc/CompileTimeTensorDesc.md).

## Constraints

None
