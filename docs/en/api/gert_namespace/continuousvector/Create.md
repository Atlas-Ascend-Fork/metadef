# Create

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:40:02.826Z pushedAt=2026-10-15T03:48:04.849Z -->

## Function

Creates a **ContinuousVector** instance. **ContinuousVector** does not support dynamic capacity expansion.

## Function Prototype

```cpp
template<typename T>  static std::unique_ptr<uint8_t[]> Create(size_t capacity, size_t &total_size)
template<typename T>  static std::unique_ptr<uint8_t[]> Create(const size_t capacity)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|T|Input|Element type contained in the instance.|
|capacity|Input|Maximum capacity of the instance.|
|total_size|Output|Total length of this instance.|

## Return Value

Pointer to this instance.

## Constraints

None

## Example

```cpp
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity); // Creates memory that can store 100 int64_t data items.
```
