# GetData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:58:19.607Z pushedAt=2026-10-15T03:48:05.114Z -->

## Function

Obtains the data pointer of **TilingData**.

## Function Prototype

```cpp
void *GetData()

const void *GetData() const
```

## Parameters

None

## Return Value

Data pointer.

## Constraints

None

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
auto tiling_data_ptr = td->GetData(); // td_buf.get() + sizeof(TilingData)
```
