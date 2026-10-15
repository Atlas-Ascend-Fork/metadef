# OriginOpType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:45:26.289Z pushedAt=2026-10-15T03:48:04.733Z -->

## Function

Sets the operator type or the operator type list of the original model.

## Function Prototype

> [!NOTE] Note
> The APIs with the string data type will be deprecated in later versions. It is recommended to use the APIs with a non-string data type.

```cpp
OpRegistrationData &OriginOpType(const std::vector<ge::AscendString> &ori_op_type_list)
OpRegistrationData &OriginOpType(const char_t *ori_op_type)
OpRegistrationData &OriginOpType(const std::initializer_list<std::string> &ori_optype_list)
OpRegistrationData &OriginOpType(const std::string &ori_optype)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ori_op_type_list/ori_optype_list|Input|Original model operator type list.|
|ori_op_type/ori_optype|Input|Original model operator type.|
