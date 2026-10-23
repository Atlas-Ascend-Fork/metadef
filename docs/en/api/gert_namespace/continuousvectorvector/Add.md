# Add

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:43:02.535Z pushedAt=2026-10-15T03:48:04.857Z -->

## Function

Adds a **ContinuousVector** element, where the capacity of the newly added **ContinuousVector** element is **inner\_vector\_capacity**.

## Function Prototype

```cpp
template<typename T> ContinuousVector *Add(size_t inner_vector_capacity)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|inner_vector_capacity|Input|Capacity of the newly added **ContinuousVector** element.|

## Return Value

First address of the newly added **ContinuousVector** element.

## Constraints

None

## Example

```cpp
// Create a ContinuousVectorVector object cvv.
...
// Add an element.
size_t inner_vector_capacity = 2;
auto cv = cvv->Add(inner_vector_capacity);
```
