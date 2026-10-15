# SerialStringToFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:19:51.717Z pushedAt=2026-10-15T03:48:04.783Z -->

## Function

Converts a string into a **Format** value.

Starting from GCC 5.1, **libstdc++** changed some APIs of **std::string** and **std::list** to better implement the C++11 specification, resulting in ABI incompatibility between the old and new versions. Therefore, it is recommended to use [AscendStringToFormat](AscendStringToFormat.md) instead of this API.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static Format SerialStringToFormat(const std::string &str)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|str|Input|**Format** string to be converted.|

## Return Value

If the input is valid, returns the converted **Format** enum value. For the enum definition, see [Format](../Format.md). If the input is invalid, returns **FORMAT\_RESERVED** and prints an error message.

## Constraints

None

## Example

```cpp
std::string format_str = "NHWC";
auto format = ge::TypeUtils::SerialStringToFormat(format_str); // 1
```
