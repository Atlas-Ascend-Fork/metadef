# GetFormatFromSub

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:13:14.630Z pushedAt=2026-10-15T03:48:04.677Z -->

## Function

Obtains the actual format based on the input primary format and subformat.

The actual format is 4 bytes in size. The high 4 bits of the first byte are the reserved field, the low 4 bits are the C0 format, bytes 2 to 3 contain the subformat information, and byte 4 contains the primary format information, as follows:

/\*

\* ---------------------------------------------------

\* |     4 bits     |      4 bits    |        2 bytes     | 1 byte  |

\* |------------|------------|----------------|--------|

\* |  reserved  | C0 format |   Sub format | format |

\* ---------------------------------------------------

\*/

## Function Prototype

```cpp
inline int32_t GetFormatFromSub(int32_t primary_format, int32_t sub_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|primary_format|Input|Primary format information, with a value not exceeding 0xffU.|
|sub_format|Input|Subformat information, with a value not exceeding 0xffffU.|

## Return Value

Actual format corresponding to the specified primary format and subformat.

## Exception Handling

None

## Constraints

None
