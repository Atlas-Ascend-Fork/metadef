# GetDataSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:58:27.378Z pushedAt=2026-10-15T03:48:05.114Z -->

## Function

Obtains the length of the tiling data.

## Function Prototype

```cpp
size_t GetDataSize() const
```

## Parameters

None

## Return Value

Tiling data length.

## Constraints

None

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
size_t data_size = td->GetDataSize(); // 0

td->SetDataSize(100U);
data_size = td->GetDataSize(); // 100
```
