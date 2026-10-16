# AppendStride

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:07:16.079Z pushedAt=2026-10-15T03:48:05.014Z -->

## Function

Appends a stride value backward. If the number of appended strides exceeds the maximum limit of strides, this function does nothing.

## Function Prototype

```cpp
Stride& AppendStride(const int64_t value)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|value|Input|Stride value to append.|

## Return Value

**this** reference.

## Constraints

None

## Example

```cpp
Stride stride0({3, 256, 256});
stride0.AppendStride(1024); // 3,256,256,1024
```
