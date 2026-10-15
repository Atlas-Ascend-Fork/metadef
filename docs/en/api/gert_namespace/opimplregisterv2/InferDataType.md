# InferDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:27:35.338Z pushedAt=2026-10-15T03:48:04.934Z -->

## Function

Registers the **InferDataType** function of an operator.

You need to write a function of the **InferDataTypeKernelFunc** type for the operator and register it using this API.

The **InferDataTypeKernelFunc** type is defined as follows:

```cpp
using InferDataTypeKernelFunc = UINT32 (*)(InferDataTypeContext *);
```

## Function Prototype

```cpp
OpImplRegisterV2 &InferDataType(InferDataTypeKernelFunc infer_datatype_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|infer_datatype_func|Input|Custom **InferDataType** function to register, which is of the **InferDataTypeKernelFunc** type.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which additionally registers the **InferDataType** function **infer\_datatype\_func**.

## Constraints

None
