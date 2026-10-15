# FormatToSerialString

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:18:19.810Z pushedAt=2026-10-15T03:48:04.780Z -->

## Function

Converts a **Format**-type value into its string representation.

Starting from GCC 5.1, libstdc++ changed some APIs of **std::string** and **std::list** to better implement the C++11 standard, resulting in ABI incompatibility between the old and new versions. Therefore, it is recommended to use [FormatToAscendString](FormatToAscendString.md) instead of this API.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static std::string FormatToSerialString(const Format format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|**Format** to be converted. For supported **Format** values, see **Format**.|

## Return Value

Returns the converted **Format** string.

## Constraints

None

## Example

```cpp
ge::Format format = ge::Format::FORMAT_NHWC;
auto format_str = ge::TypeUtils::FormatToSerialString(format); // "NHWC"
```
