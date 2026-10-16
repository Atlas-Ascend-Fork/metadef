# SetMin

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:53:05.350Z pushedAt=2026-10-15T03:48:04.982Z -->

## Function

Sets the smallest **T** object pointer.

## Function Prototype

```cpp
void SetMin(T *min)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**min**|Input|Smallest **T** object pointer.|

## Return Value

None

## Constraints

None

## Example

```cpp
Range<int> range;
int min = -1;
range.SetMin(&min);
```
