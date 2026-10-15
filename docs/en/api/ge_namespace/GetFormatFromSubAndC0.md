# GetFormatFromSubAndC0

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:14:19.813Z pushedAt=2026-10-15T03:48:04.677Z -->

## Function

Obtains the actual format based on the input primary format, subformat, and C0 format information.

The actual format is 4 bytes in size. The upper four bits of the first byte are a reserved field, the lower four bits are the C0 format, bytes 2 to 3 contain the subformat information, and byte 4 contains the primary format information, as follows:

/\*

\* ---------------------------------------------------

\* |     4 bits    |      4 bits      |        2 bytes    | 1 byte  |

\* |------------|-------------|----------------|--------|

\* |  reserved  | C0 format |   Sub format   | format |

\* ---------------------------------------------------

\*/

## Function Prototype

```cpp
inline int32_t GetFormatFromSubAndC0(int32_t primary_format, int32_t sub_format, int32_t c0_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|primary_format|Input|Primary format information, with a value not exceeding 0xffU.|
|sub_format|Input|Subformat information, with a value not exceeding 0xffffU.|
|c0_format|Input|C0 format information, with a value not exceeding 0xfU.|

## Return Value

Actual format corresponding to the specified primary\_format, sub\_format, and c0\_format.

## Exception Handling

None

## Constraints

None
