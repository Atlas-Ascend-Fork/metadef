# GetSubFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:16:01.085Z pushedAt=2026-10-15T03:48:04.681Z -->

## Function

Parses the subformat information from the actual format.

## Function Prototype

```cpp
inline int32_t GetSubFormat(int32_t format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Actual format (4 bytes in size, where the high four bits of the first byte are reserved, the low four bits are the C0 format segment, bytes 2-3 contain the subformat information, and byte 4 contains the primary format information).|

## Return Value

Subformat contained in the actual format.

## Exception Handling

None

## Constraints

None
