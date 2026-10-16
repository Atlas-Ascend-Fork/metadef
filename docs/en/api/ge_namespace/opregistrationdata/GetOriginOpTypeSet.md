# GetOriginOpTypeSet

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:43:02.417Z pushedAt=2026-10-15T03:48:04.728Z -->

## Function

Obtains the operator type set of the original model.

## Function Prototype

> [!NOTE] Note
> The API with the string data type will be deprecated in later versions. Use the API with a non-string data type instead.

```cpp
std::set<std::string> GetOriginOpTypeSet () const
Status GetOriginOpTypeSet(std::set<ge::AscendString> &ori_op_type) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**ori_op_type**|Output|Operator type set of the original model.|

## Constraints

None
