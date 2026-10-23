# SetDataSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:59:28.879Z pushedAt=2026-10-15T03:48:05.116Z -->

## Function

Sets the length of tiling data.

## Function Prototype

```cpp
void SetDataSize(const size_t size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|size|Input|Length of tiling data.|

## Return Value

None

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
