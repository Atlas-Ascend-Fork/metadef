# ImplyType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:44:05.096Z pushedAt=2026-10-15T03:48:04.729Z -->

## Function

Sets the operator execution mode.

## Function Prototype

```cpp
OpRegistrationData &ImplyType(const domi::ImplyType &imply_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**imply_type**|Input|Operator execution mode.<br>`enum class ImplyType : unsigned int{BUILDIN = 0,// Built-in operator, which is executed normally by OME. TVM,       // Compiled into a TVM bin file for execution. CUSTOM,     // Custom computation logic defined by the user, executed on the CPU. AI_CPU,      // AI CPU custom operator type. INVALID = 0xFFFFFFFF,};`|
