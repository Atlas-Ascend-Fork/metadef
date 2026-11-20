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

- Returns the corresponding C0 value `2^(x-1)` decoded from the encoding field `x` if the C0 format is included. For example, a field value of `5` returns `16`.
- Returns **-1** if the C0 format is not included.

## Exception Handling

None

## Constraints

When setting the actual format, the C0 format field `x` in the low 4 bits of the first byte ranges from 1 to 15; `GetC0Value` returns `2^(x-1)`. If the C0 format is not set, `-1` is returned.
