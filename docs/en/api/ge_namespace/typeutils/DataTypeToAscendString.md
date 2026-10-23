# DataTypeToAscendString

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:16:58.738Z pushedAt=2026-10-15T03:48:04.778Z -->

## Function

Converts a **DataType** value into its string representation.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static AscendString DataTypeToAscendString(const DataType &data_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data_type|Input|**DataType** to be converted. For supported **DataType** values, see [DataType](../DataType.md).|

## Return Value

Returns the converted **DataType** string of the [AscendString](../ascendstring/AscendString.md) type.

## Constraints

None

## Example

```cpp
DataType data_type = ge::DT_UINT32;
auto type_str = ge::TypeUtils::DataTypeToAscendString(data_type); // "DT_UINT32"
const char *ptr = type_str.GetString();  // Obtain the char* pointer.
```
