# NullableOutputs

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:30:55.716Z pushedAt=2026-10-15T03:48:04.938Z -->

## Function

Marks the outputs of an operator that can be null.

## Function Prototype

```cpp
 OpImplRegisterV2 &NullableOutputs(std::initializer_list<int32_t> outputs)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**outputs**|Input|Specifies the list of output indexes. For example, outputs={0, 3} indicates that the 0th and 3rd outputs of the operator can be null.|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the **NullableOutput** function.
