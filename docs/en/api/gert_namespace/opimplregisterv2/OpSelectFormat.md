# OpSelectFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:32:24.190Z pushedAt=2026-10-15T03:48:04.941Z -->

## Function

Registers a format selection function to obtain the data type and data format, allowing the operator to check the support information on its own.

## Function Prototype

```cpp
OpImplRegisterV2 &OpSelectFormat(OP_CHECK_FUNC_V2 op_select_format_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**select_format_func**|Input|**OP_CHECK_FUNC_V2** function to be registered. The **OP_CHECK_FUNC_V2** type is defined as follows:<br>`using OP_CHECK_FUNC_V2 = ge::graphStatus (*)(const OpCheckContext *context, ge::AscendString &result);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **OP\_CHECK\_FUNC\_V2** function.

## Constraints

None
