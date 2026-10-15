# GetCapacity

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:57:56.413Z pushedAt=2026-10-15T03:48:05.113Z -->

## Function

Obtains the maximum tiling data length that this instance can hold.

## Function Prototype

```cpp
size_t GetCapacity() const
```

## Parameters

None

## Return Value

Maximum tiling data length.

## Constraints

None

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
size_t cap = td->GetCapacity(); // 100U
```
