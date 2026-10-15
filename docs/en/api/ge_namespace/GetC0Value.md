# GetC0Value

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:11:43.621Z pushedAt=2026-10-15T03:48:04.675Z -->

## Function

Parses the C0 format information from the actual format.

## Function Prototype

```cpp
inline int64_t GetC0Value(int32_t format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Actual format (4 bytes in size, where the high 4 bits of byte 1 are a reserved field, the low 4 bits are the C0 format, bytes 2-3 are the sub-format information, and byte 4 is the main format information).|

## Return Value

- Returns the C0 format contained in the actual format if the C0 format is included.
- Returns **-1** if the C0 format is not included.

## Exception Handling

None

## Constraints

When setting the actual format, the range of the C0 format in the low 4 bits of the first byte supports only x=\(0001\~1111\), and the actually obtained C0 value is 2^x-1.
