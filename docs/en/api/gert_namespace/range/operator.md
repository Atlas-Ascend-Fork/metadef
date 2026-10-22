# operator==

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:51:32.838Z pushedAt=2026-10-15T03:48:04.979Z -->

## Function

Checks whether this range object is equal to another range object. Two objects are equal if the addresses of their upper and lower bounds are the same, or if the values of their upper and lower bounds are the same.

## Function Prototype

```cpp
bool operator==(const Range<T>&rht) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|rht|Input|Another range object.|

## Return Value

**true**: equal; **false**: not equal.

## Constraints

None

## Example

```cpp
int min = 0;
int max = 1024;
int max2 = 1024;
Range<int> range1(&min, &max); // The upper bound is 1024, and the lower bound is 0.
Range<int> range2(&min, &max); // The upper bound is 1024, and the lower bound is 0.
Range<int> range3(&min, &max2); // The upper bound is 1024, and the lower bound is 0.

auto ret1 = range1 == range2; // true
auto ret2 = range1 == range3; // true
```
