# GetSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:44:48.966Z pushedAt=2026-10-15T03:48:04.859Z -->

## Function

Obtains the actual number of elements currently stored.

## Function Prototype

```cpp
size_t GetSize() const
```

## Parameters

None

## Return Value

Actual number of elements currently stored.

## Constraints

None

## Example

```cpp
// Create a ContinuousVectorVector object cvv.
...
// Add elements.
...
auto cv = cvv->add(inner_vector_capacity);
...
// Obtain the actual number of elements currently stored.
auto size = cvv->GetSize();
```
