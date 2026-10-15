# GetOverHeadLength

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:44:31.034Z pushedAt=2026-10-15T03:48:04.858Z -->

## Function

Obtains the length of the data description information.

## Function Prototype

```cpp
static size_t GetOverHeadLength(const size_t capacity)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|capacity|Input|Maximum capacity of the instance.|

## Return Value

Length of the data description information.

## Constraints

None

## Example

```cpp
size_t capacity = 100U;
auto length = ContinuousVectorVector::GetOverHeadLength(capacity);
```
