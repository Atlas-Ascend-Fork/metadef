# SerialStringToDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:19:21.961Z pushedAt=2026-10-15T03:48:04.781Z -->

## Function

Converts the string representation of **DataType** to a **DataType** value.

Starting from GCC 5.1, libstdc++ changed some APIs of **std::string** and **std::list** to better implement the C++11 specification, resulting in ABI incompatibility between old and new versions. Therefore, it is recommended to use [AscendStringToDataType](AscendStringToDataType.md) instead of this API.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static DataType SerialStringToDataType(const std::string &str)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|str|Input|String form of the **DataType** to be converted.|

## Return Value

If the input is valid, returns the converted **DataType** enum value. For the enum definition, see [DataType](../DataType.md). If the input is invalid, returns **DT\_UNDEFINED** and prints an error log.

## Constraints

None

## Example

```cpp
std::string type_str = "DT_UINT32";
auto data_type = ge::TypeUtils::SerialStringToDataType(type_str); // 8
```
