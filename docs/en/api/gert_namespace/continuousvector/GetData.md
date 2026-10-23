# GetData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:41:32.092Z pushedAt=2026-10-15T03:48:04.851Z -->

## Function

Obtains the pointer address of the first element. The data in **\[GetData\(\), reinterpret\_cast\<T \*\>\(GetData\(\)\)** + **GetSize\(\)\)** is the data currently stored in the container.

## Function Prototype

```cpp
const void *GetData() const
```

## Parameters

None

## Return Value

Pointer address of the first element.

## Constraints

None

## Example

```cpp
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<ContinuousVector *>(cv_holder.get());
auto cap = cv->GetData();
```
