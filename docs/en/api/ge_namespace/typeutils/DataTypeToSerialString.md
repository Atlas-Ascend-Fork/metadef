# DataTypeToSerialString

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:17:01.443Z pushedAt=2026-10-15T03:48:04.779Z -->

## Function

Converts a **DataType** value into its string representation.

Starting from GCC 5.1, libstdc++ changed some APIs of **std::string** and **std::list** to better implement the C++11 standard, resulting in ABI incompatibility between old and new versions. Therefore, it is recommended to use [DataTypeToAscendString](DataTypeToAscendString.md) instead of this API.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static std::string DataTypeToSerialString(const DataType data_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data_type|Input|**DataType** to be converted. For supported **DataType** values, see **DataType**.|

## Return Value

Returns the converted **DataType** string.

## Constraints

None

## Example

```cpp
DataType data_type = ge::DT_UINT32;
auto type_str = ge::TypeUtils::DataTypeToSerialString(data_type); // "DT_UINT32"
```
