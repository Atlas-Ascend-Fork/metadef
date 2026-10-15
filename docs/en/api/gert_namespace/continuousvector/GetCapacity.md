# GetCapacity

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:40:54.452Z pushedAt=2026-10-15T03:48:04.851Z -->

## Function

Obtains the maximum number of elements that can be stored.

## Function Prototype

```cpp
size_t GetCapacity() const
```

## Parameters

None

## Return Value

Maximum number of elements that can be stored.

## Constraints

None

## Example

```cpp
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<ContinuousVector *>(cv_holder.get());
auto cap = cv->GetCapacity(); // 100U
```
