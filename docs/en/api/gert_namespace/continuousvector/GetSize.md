# GetSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:41:49.604Z pushedAt=2026-10-15T03:48:04.852Z -->

## Function

Obtains the number of currently stored elements.

## Function Prototype

```cpp
size_t GetSize() const
```

## Parameters

None

## Return Value

Number of currently stored elements.

## Constraints

None

## Example

```cpp
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<ContinuousVector *>(cv_holder.get());
auto size = cv->GetSize(); // 0U
```
