# CalcTotalSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:56:39.622Z pushedAt=2026-10-15T03:48:05.110Z -->

## Function

Calculates the memory space occupied by a **TilingData** instance based on the maximum capacity.

## Function Prototype

```cpp
static ge::graphStatus CalcTotalSize(const size_t cap_size, size_t &total_size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|cap_size|Input|Maximum capacity, in bytes.|
|total_size|Output|Memory space, in bytes.|

## Return Value

- Returns **ge::GRAPH\_SUCCESS** on success.
- Returns **ge::GRAPH\_FAILED** on failure.

## Constraints

None

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
size_t total_size = 0U;
auto ret = td->CalcTotalSize(td.GetCapacity, total_size); // total_size = 100 + sizeof(TilingData)
```
