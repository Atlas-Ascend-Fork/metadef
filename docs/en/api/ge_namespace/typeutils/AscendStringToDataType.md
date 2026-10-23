# AscendStringToDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:15:37.004Z pushedAt=2026-10-15T03:48:04.776Z -->

## Function

Converts the string representation of **DataType** into a **DataType** value.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static DataType AscendStringToDataType(const AscendString &str)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|str|Input|String form of **DataType** to be converted, of the **AscendString** type.|

## Return Value

If the input is valid, returns the converted **DataType** enum value. For the enum definition, see [DataType](../DataType.md). If the input is invalid, returns **DT\_UNDEFINED** and prints an error log.

## Constraints

None

## Example

```cpp
ge::AscendString type_str("DT_UINT32");
auto data_type = ge::TypeUtils::AscendStringToDataType(type_str); // 8
```
