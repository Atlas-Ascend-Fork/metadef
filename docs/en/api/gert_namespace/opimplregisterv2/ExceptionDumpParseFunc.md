# ExceptionDumpParseFunc

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:26:00.761Z pushedAt=2026-10-15T03:48:04.931Z -->

## Function

Registers an exception handling function to execute user-defined exception handling logic when an aic error occurs on an operator.

## Function Prototype

```cpp
OpImplRegisterV2 &ExceptionDumpParseFunc(ExceptionDumpFunc exception_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|exception_func|Input|ExceptionDumpFunc function to be registered. The ExceptionDumpFunc type is defined as follows:<br>`using ExceptionDumpFunc = void (*)(aclrtExceptionInfo *exception_info, void *reserved);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, with the **ExceptionDumpFunc** function newly registered.

## Constraints

None
