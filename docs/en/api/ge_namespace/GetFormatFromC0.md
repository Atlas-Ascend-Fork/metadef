# GetFormatFromC0

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:12:16.853Z pushedAt=2026-10-15T03:48:04.676Z -->

## Function

Obtains the actual format based on the input format and C0 format information.

The actual format is 4 bytes in size. The upper four bits of the first byte are a reserved field, the lower four bits are the C0 format, bytes 2-3 contain the sub-format information, and byte 4 contains the main format information, as follows:

/\*

\* ---------------------------------------------------

\* |     4 bits     |      4 bits    |        2 bytes    | 1 byte  |

\* |------------|------------|----------------|--------|

\* |  reserved  | C0 format |   Sub format | format |

\* ---------------------------------------------------

\*/

## Function Prototype

```cpp
inline int32_t GetFormatFromC0(int32_t format, int32_t c0_format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Sub-format and main format information, with a value not exceeding 0xffffffU.|
|c0_format|Input|C0 format information, with a value not exceeding 0xfU.|

## Return Value

The actual format corresponding to the specified format and c0\_format.

## Exception Handling

None

## Constraints

None
