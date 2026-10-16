# GetMax

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:50:43.248Z pushedAt=2026-10-15T03:48:04.977Z -->

## Function

Obtains the pointer to the largest **T** object.

## Function Prototype

```cpp
const T *GetMax() const
T *GetMax()
```

## Parameters

None

## Return Value

Returns the pointer to the largest **T** object.

## Constraints

None

## Example

```cpp
int min = -1;
int max = 1024;
Range<int> range(&min, &max);

auto ret = range.GetMax(); // The ret pointer points to max.
```
