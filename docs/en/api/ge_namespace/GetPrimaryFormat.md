# GetPrimaryFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:15:03.663Z pushedAt=2026-10-15T03:48:04.679Z -->

## Function

Parses the primary format information from the actual format.

## Function Prototype

```cpp
inline int32_t GetPrimaryFormat(int32_t format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Actual format (4 bytes in size, where the upper four bits of the first byte are a reserved field, the lower four bits are the C0 format, bytes 2-3 contain the subformat information, and byte 4 contains the primary format information).|

## Return Value

Primary format contained in the actual format.

## Exception Handling

None

## Constraints

None
