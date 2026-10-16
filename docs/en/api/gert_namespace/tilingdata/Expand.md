# Expand

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:57:39.618Z pushedAt=2026-10-15T03:48:05.112Z -->

## Function

Expands **TilingData** by the specified size.

## Function Prototype

```cpp
void *Expand(size_t size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|size|Input|Size to expand, in bytes.|

## Return Value

Returns the memory address of **TilingData** after expansion by specified **size**.

## Constraints

The total size after expansion must not exceed the maximum capacity of **TilingData**.

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
auto ptr = td->Expand(64U);
size_t cap = td->GetCapacity(); // 64U
```
