# DelInputWithOriginalType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:39:59.793Z pushedAt=2026-10-15T03:48:04.721Z -->

## Function

Deletes the specified input edge of an operator based on the operator type.

## Function Prototype

> [!NOTE] Note
> The API with the string data type will be deprecated in later versions. You are advised to use the API with a non-string data type.

```cpp
OpRegistrationData &DelInputWithOriginalType(int32_t input_idx, const std::string &ori_type)
OpRegistrationData &DelInputWithOriginalType(int32_t input_idx, const char_t *ori_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|input_idx|Input|Number of the input edge to be deleted.|
|ori_type|Input|Original operator type of the node to be deleted.|

## Constraints

None
