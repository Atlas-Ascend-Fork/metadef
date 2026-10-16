# GetMin

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:50:57.818Z pushedAt=2026-10-15T03:48:04.978Z -->

## Function

Obtains the pointer to the smallest **T** object.

## Function Prototype

```cpp
const T *GetMin() const
T *GetMin()
```

## Parameters

None

## Return Value

Returns the pointer to the smallest **T** object.

## Constraints

None

## Example

```cpp
int min = -1;
int max = 1024;
Range<int> range(&min, &max);

auto ret = range.GetMin(); // The ret pointer points to min.
```
