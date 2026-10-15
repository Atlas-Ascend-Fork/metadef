# Init

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:44:55.366Z pushedAt=2026-10-15T03:48:04.860Z -->

## Function

Initializes the **ContinuousVectorVector** class.

## Function Prototype

```cpp
void Init(const size_t capacity)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**capacity**|Input|Maximum capacity of the instance.|

## Return Value

None

## Constraints

None

## Example

```cpp
size_t total_length = 1000U; // Set this value based on the actual amount of data to be stored.
size_t capacity = 100U;
std::vector<uint8_t> buf(total_length);
auto cvv = new (buf.data()) ContinuousVectorVector();
cvv->Init(capacity);
```
