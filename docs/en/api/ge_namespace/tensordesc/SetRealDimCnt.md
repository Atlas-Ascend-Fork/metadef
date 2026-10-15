# SetRealDimCnt

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:11:11.465Z pushedAt=2026-10-15T03:48:04.770Z -->

## Function

Sets the actual number of dimensions of a tensor in **TensorDesc**.

The shape returned by the [GetShape](GetShape.md) API may contain dimensions padded with 1, so this API can be used to set the actual number of dimensions of the shape.

## Function Prototype

```cpp
void SetRealDimCnt(const int64_t real_dim_cnt)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|real_dim_cnt|Input|Actual number of data dimensions of the **TensorDesc** to be set.|

## Return Value

None

## Exception Handling

None

## Constraints

None
