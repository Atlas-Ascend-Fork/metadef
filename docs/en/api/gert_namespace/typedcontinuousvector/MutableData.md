# MutableData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T05:00:42.973Z pushedAt=2026-10-15T03:48:05.120Z -->

## Function

Obtains the pointer address of the first element. **\[MutableData\(\),  reinterpret\_cast\<T \*\>\(MutableData\(\)\)** + **GetSize\(\)\)**  contains the data currently stored in the container.

Compared with the [GetData](GetData.md) API, the content pointed to by the pointer address is mutable.

## Function Prototype

```cpp
T *MutableData()
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
auto cv = reinterpret_cast<TypedContinuousVector *>(cv_holder.get());
auto cap = cv->MutableData<int64_t>();
```
