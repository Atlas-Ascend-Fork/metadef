# GetC0Format

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:11:21.046Z pushedAt=2026-10-15T03:48:04.674Z -->

## Function

Obtains the value of the C0 format based on the actual format. The C0 value is a parameter required by the AI processor-specific data format. For example, in NC1HWC0, the last dimension represents the C0 value. The C0 value varies across different AI processors and is carried by the C0 format.

The actual format is 4 bytes in size. The upper four bits of the first byte are a reserved field, the lower four bits are the C0 format, bytes 2 to 3 are the sub format information, and byte 4 is the main format information, as shown below:

/\*

\* ---------------------------------------------------

\* |     4 bits     |      4 bits     |        2 bytes    | 1 byte  |

\* |------------|-------------|----------------|--------|

\* |  reserved  | C0 format |   Sub format | format |

\* ---------------------------------------------------

\*/

## Function Prototype

```cpp
inline int32_t GetC0Format(int32_t format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Actual format (4 bytes in size, where the upper four bits of the first byte are a reserved field, the lower four bits are the C0 format segment, bytes 2 to 3 are the sub format information, and byte 4 is the main format information).|

## Return Value

- If the C0 format is included, returns the value of the C0 format.
- If no C0 format is included, returns **0**.

## Exception Handling

None

## Constraints

None
