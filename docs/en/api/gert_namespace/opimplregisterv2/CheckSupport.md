# CheckSupport

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:25:29.939Z pushedAt=2026-10-15T03:48:04.930Z -->

## Function

Registers a function that checks whether an operator is supported.

## Function Prototype

```cpp
OpImplRegisterV2 &CheckSupport(OP_CHECK_FUNC_V2 check_support_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|check_support_func|Input|OP_CHECK_FUNC_V2 function to be registered. The **OP_CHECK_FUNC_V2** type is defined as follows:<br>`using OP_CHECK_FUNC_V2 = ge::graphStatus (*)(const OpCheckContext *context, ge::AscendString &result);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator. The newly registered **OP\_CHECK\_FUNC\_V2** function is added to the object.

## Constraints

None
