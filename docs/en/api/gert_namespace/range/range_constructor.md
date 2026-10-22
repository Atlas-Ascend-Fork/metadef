# Range Constructor

<!-- md-trans-meta sourceCommit=1bfbd0f0dd6167ab870bed0b96c0f83575d5fca8 translatedAt=2026-10-16T01:39:07.817Z pushedAt=2026-10-16T02:00:17.878Z -->

## Function

The range constructor supports the following three construction methods:

- You can use the default constructor to create a range instance whose lower and upper bounds are both **nullptr**.
- You can also create a range instance by specifying the lower and upper bounds.
- You can also pass only a pointer of any type to create a range instance whose lower and upper bounds are identical.

## Function Prototype

```cpp
Range() // Default constructor. Both the lower and upper bounds are null pointers.
Range(T *min, T* max) : min_(min), max_(max) // The user specifies max as the upper bound and min as the lower bound.
explicit Range(T *same_ele) : min_(same_ele), max_(same_ele) // Both min and max are same_ele.
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|min|Input|Pointer to the lower bound, of type **T***.|
|max|Input|Pointer to the upper bound, of type **T***.|
|same_ele|Input|Used when constructing a range instance with identical lower and upper bounds. Both the lower and upper bounds are assigned the value of **same_ele**, of type **T***.|

## Return Value

Returns the range object constructed as specified by the user.

## Constraints

None

## Example

```cpp
// 1. Default constructor.
Range<int> range1; // Both the lower and upper bounds are nullptr.
// 2. User-specified lower and upper bounds.
int min = 0;
int max = 1024;
Range<int> range2(&min, &max); // The upper bound is 1024 and the lower bound is 0.
// 3. Construct a range with identical lower and upper bounds.
Range<int> range3(&min); // Both the lower and upper bounds are 0.
```
