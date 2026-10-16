# DataFormatToFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:16:28.643Z pushedAt=2026-10-15T03:48:04.778Z -->

## Function

Converts a data format string into a **Format**-type value.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static Format DataFormatToFormat(const AscendString &str)
static Format DataFormatToFormat(const std::string &str)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|str|Input|**Format** string to be converted. Starting from GCC 5.1, libstdc++ changed some APIs of **std::string** and **std::list** to better implement the C++11 standard, resulting in ABI incompatibility between the old and new versions. Therefore, it is recommended to use the API whose input parameter is of the **AscendString** type.|

## Return Value

If the input is valid, returns the converted **Format** enum value. For the enum definition, see [Format](../Format.md). Only some formats are supported. For details, see [Constraints](#constraints). If the input is invalid, returns **FORMAT\_RESERVED** and prints an error message.

## Constraints

Only the following formats are supported:

"NCHW": FORMAT\_NCHW

"NHWC": FORMAT\_NHWC

"NDHWC": FORMAT\_NDHWC

"NCDHW": FORMAT\_NCDHW

"ND": FORMAT\_ND

## Example

```cpp
// If the API with the AscendString input parameter is used (recommended)
ge::AscendString format_str = "NHWC";
auto format = ge::TypeUtils::DataFormatToFormat(format_str); // 1

// If the API with the std:string input parameter is used (not recommended)
std::string format_str = "NHWC";
auto format = ge::TypeUtils::DataFormatToFormat(format_str); // 1
```
