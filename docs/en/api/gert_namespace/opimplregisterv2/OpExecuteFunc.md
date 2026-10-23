# OpExecuteFunc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:31:48.087Z pushedAt=2026-10-15T03:48:04.940Z -->

## Function

In scenarios where a single operator contains multi-kernel combined execution logic, the operator can use this API to set an operator-level callback function, in which the multi-kernel dispatch is implemented. This is a reserved feature and is not supported yet.

## Function Prototype

```cpp
OpImplRegisterV2 &OpExecuteFunc(OpExecFunc op_execute_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_execute_func|Input|Registered custom **OpExecuteFunc** function, which is of the type **OpExecFunc**. The **OpExecFunc** type is defined as follows:<br>`using OpExecFunc = UINT32 (*)(OpExecuteContext *);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which additionally registers an operator-level callback function.

## Constraints

None
