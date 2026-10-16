# Get

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:43:57.252Z pushedAt=2026-10-15T03:48:04.859Z -->

## Function

Obtains the first address of the element at **index**.

## Function Prototype

```cpp
const ContinuousVector *Get(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Element **index**.|

## Return Value

First address of the element at **index**.

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
// Obtain the first address of the element at index 0.
auto cv1 = cvv->Get(0U);
```
