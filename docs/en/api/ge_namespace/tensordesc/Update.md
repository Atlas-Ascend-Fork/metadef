# Update

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:15:16.065Z pushedAt=2026-10-15T03:48:04.776Z -->

## Function

Updates the **Shape**, **Format**, and **DataType** attributes of **TensorDesc**.

## Function Prototype

```cpp
void Update(const Shape &shape, Format format = FORMAT_ND, DataType dt = DT_FLOAT)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|shape|Input|**Shape** object to be updated.|
|format|Input|**Format** object to be updated, defaulting to **FORMAT_ND**.|
|dt|Input|**DataType** object to be updated, defaulting to **DT_FLOAT**.|

## Return Value

None

## Exception Handling

None

## Constraints

None
