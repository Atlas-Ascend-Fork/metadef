# FormatToAscendString

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:17:58.781Z pushedAt=2026-10-15T03:48:04.779Z -->

## Function

Converts a **Format** value into its string representation.

To use this API, include the **type\_utils.h** header file.

```cpp
#include "graph/utils/type_utils.h"
```

## Function Prototype

```cpp
static AscendString FormatToAscendString(const Format &format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|**Format** to be converted. For supported formats, see **Format**.|

## Return Value

Converted format string of the [AscendString](../ascendstring/AscendString.md) type.

## Constraints

None

## Example

```cpp
ge::Format format = ge::Format::FORMAT_NHWC;
auto format_str = ge::TypeUtils::FormatToAscendString(format);
const char *ptr = format_str.GetString();
```
