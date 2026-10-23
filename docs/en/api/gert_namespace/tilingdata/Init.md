# Init

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:58:50.591Z pushedAt=2026-10-15T03:48:05.116Z -->

## Function

Initializes **TilingData**.

## Function Prototype

```cpp
void Init(const size_t cap_size, void *const data)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|cap_size|Input|Maximum capacity.|
|data|Input|Address of the tiling data.|

## Return Value

None

## Constraints

None

## Example

```cpp
size_t cap_size = 100U;
size_t total_size = cap_size + sizeof(TilingData);
auto td_buf = std::unique_ptr<uint8_t[]>(new (std::nothrow) uint8_t[total_size]());
auto td = reinterpret_cast<TilingData *>(td_buf.get());
td->Init(cap_size, td_buf.get() + sizeof(TilingData)); // memory tiling.
```
