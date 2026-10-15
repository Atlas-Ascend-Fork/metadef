# HasC0Format

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:16:34.176Z pushedAt=2026-10-15T03:48:04.681Z -->

## Function

Checks whether the actual format contains the C0 format.

## Function Prototype

```cpp
inline bool HasC0Format(int32_t format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Actual format (4 bytes in size, where the high four bits of the first byte are a reserved field, the low four bits are the C0 format, bytes 2-3 are subformat information, and byte 4 is primary format information).|

## Return Value

- **true**: The actual format contains the C0 format.
- **false**: The actual format does not contain the C0 format.

## Exception Handling

None

## Constraints

None
