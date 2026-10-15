# SetMax

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:52:28.469Z pushedAt=2026-10-15T03:48:04.981Z -->

## Function

Sets the largest **T** object pointer.

## Function Prototype

```cpp
void SetMax(T *max)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|max|Input|Pointer to the largest **T** object.|

## Return Value

None

## Constraints

None

## Example

```cpp
Range<int> range;
int max = 1024;
range.SetMax(&max);
```
