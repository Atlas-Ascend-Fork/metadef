# DelInputWithCond

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:39:54.295Z pushedAt=2026-10-15T03:48:04.722Z -->

## Function

Deletes the specified input edge of an operator based on the operator attributes.

## Function Prototype

> [!NOTE] Note
> The API with the string data type will be deprecated in later versions. You are advised to use the API with a non-string data type.

```cpp
OpRegistrationData &DelInputWithCond(int32_t inputIdx, const std::string &attrName, bool attrValue)
OpRegistrationData &DelInputWithCond(int32_t input_idx, const char_t *attr_name, bool attr_value)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|input_idx/inputIdx|Input|Index of the input edge to be deleted.|
|attr_name/attrName|Input|Attribute name.|
|attr_value/attrValue|Input|Attribute value.|

## Constraints

None
