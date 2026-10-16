# GetDataTypeLength

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:18:53.984Z pushedAt=2026-10-15T03:48:04.781Z -->

## Function

Obtains the memory size occupied by a data type.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static bool GetDataTypeLength(const ge::DataType data_type, uint32_t &length)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data_type|Input|Data type.|
|length|Output|Memory size occupied by the data type, in bytes.|

## Return Value

Returns **true** if the data type is obtained successfully; returns **false** if **data\_type** is not supported.

## Constraints

None

## Example

```cpp
uint32_t type_length;
ge::DataType data_type = ge::DT_INT8;
const bool ret = ge::TypeUtils::GetDataTypeLength(data_type, type_length); // type_length 1
if (!ret) {
  // ...
}
```
