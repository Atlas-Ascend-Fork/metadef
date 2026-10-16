# OpRegistrationData Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:44:31.650Z pushedAt=2026-10-15T03:48:04.731Z -->

## Function

**OpRegistrationData** constructor and destructor.

## Function Prototype

> [!NOTE] Note
> APIs with the string data type will be deprecated in later versions. It is recommended to use APIs with a non-string data type.

```cpp
OpRegistrationData(const std::string &om_optype)
OpRegistrationData(const char_t *om_optype)
~OpRegistrationData()
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|om_optype|Input|Specifies the operator type supported by the model adapted to the AI processor.|

## Return Value

The **OpRegistrationData** constructor returns an object of the **OpRegistrationData** type.

## Exception Handling

None

## Constraints

None
