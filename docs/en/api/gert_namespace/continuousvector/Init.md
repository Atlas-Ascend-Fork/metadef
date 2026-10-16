# Init

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:41:51.791Z pushedAt=2026-10-15T03:48:04.852Z -->

## Function

Initializes this instance with the maximum capacity.

## Function Prototype

```cpp
void Init(const size_t capacity)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|capacity|Input|Maximum capacity of the instance.|

## Return Value

None

## Constraints

None

## Example

```cpp
size_t capacity = 100U;
size_t total_size = capacity * sizeof(int64_t) + sizeof(ContinuousVector);
auto holder = std::unique_ptr<uint8_t[]>(new (std::nothrow) uint8_t[total_size]);
reinterpret_cast<ContinuousVector *>(holder.get())->Init(capacity); // 100U
```
