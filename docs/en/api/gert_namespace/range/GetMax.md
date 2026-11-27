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

Returns the pointer to the largest **T** object. If the maximum-value pointer is null, such as after default construction or **SetMax(nullptr)**, returns **nullptr**.

## Constraints

The caller must check for **nullptr** before dereferencing the returned pointer.

## Example

```cpp
int min = -1;
int max = 1024;
gert::Range<int> range(&min, &max);

auto ret = range.GetMax(); // The ret pointer points to max.
```
