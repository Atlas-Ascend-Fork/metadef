# HasSubFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:16:59.451Z pushedAt=2026-10-15T03:48:04.682Z -->

## Function

Checks whether the actual format contains a subformat.

## Function Prototype

```cpp
inline bool HasSubFormat(int32_t format)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|format|Input|Actual format (4 bytes in size, where the upper four bits of byte 1 are a reserved field, the lower four bits are the C0 format, bytes 2-3 contain the subformat information, and byte 4 contains the primary format information).|

## Return Value

- **true**: The actual format contains a subformat.
- **false**: The actual format does not contain a subformat.

## Exception Handling

None

## Constraints

None
