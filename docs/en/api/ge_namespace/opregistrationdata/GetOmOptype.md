# GetOmOptype

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:42:35.443Z pushedAt=2026-10-15T03:48:04.727Z -->

## Function

Obtains the operator type of the model.

## Function Prototype

> [!NOTE] Note
> The API with the string data type will be deprecated in later versions. You are advised to use the API with a non-string data type.

```cpp
std::string GetOmOptype () const
Status GetOmOptype(ge::AscendString &om_op_type) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**om_op_type**|Output|Operator type of the model.|

## Constraints

None
