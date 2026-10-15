# AscendStringToFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:16:06.278Z pushedAt=2026-10-15T03:48:04.777Z -->

## Function

Converts a string to a **Format** value.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static Format AscendStringToFormat(const AscendString &str)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|str|Input|**Format** string to be converted, of the **AscendString** type.|

## Return Value

If the input is valid, returns the converted **Format** enum value. For the enum definition, see [Format](../Format.md). If the input is invalid, returns **FORMAT\_RESERVED** and prints an error message.

## Constraints

None

## Example

```cpp
ge::AscendString format_str("NHWC");
auto format = ge::TypeUtils::AscendStringToFormat(format_str); // 1
```
