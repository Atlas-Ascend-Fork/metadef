# CreateCap

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:57:28.783Z pushedAt=2026-10-15T03:48:05.111Z -->

## Function

Creates a **TilingData** instance with the specified maximum capacity.

## Function Prototype

```cpp
static std::unique_ptr<uint8_t[]> CreateCap(const size_t cap_size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|cap_size|Input|Maximum capacity, in bytes.|

## Return Value

Pointer to the **TilingData** instance.

## Constraints

None

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
```
