# AppendDim

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:57:30.137Z pushedAt=2026-10-15T03:48:04.991Z -->

## Function

Appends a dim value backward. If the number of appended dims exceeds the maximum limit of **Shape**, this function does nothing.

## Function Prototype

```cpp
Shape& AppendDim(const int64_t value)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|value|Input|Appended dim value.|

## Return Value

**this** reference.

## Constraints

None

## Example

```cpp
Shape shape0({3, 256, 256});
shape0.AppendDim(1024); // 3,256,256,1024
```
