# TensorDesc Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:13:51.716Z pushedAt=2026-10-15T03:48:04.775Z -->

## Function

**TensorDesc** constructor and destructor.

## Function Prototype

```cpp
TensorDesc()
~TensorDesc() = default
explicit TensorDesc(Shape shape, Format format = FORMAT_ND, DataType dt = DT_FLOAT)
TensorDesc(const TensorDesc &desc)
TensorDesc(TensorDesc &&desc)
TensorDesc &operator=(const TensorDesc &desc)
TensorDesc &operator=(TensorDesc &&desc)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|shape|Input|**Shape** object.|
|format|Input|**Format** object. The default value is **FORMAT_ND**. For the definition of the **Format** data type, see **Format**.|
|dt|Input|**DataType** object. The default value is **DT_FLOAT**. For the definition of the **DataType** data type, see **DataType**.|
|desc|Input|**TensorDesc** object to be copied or moved.|

## Return Value

The **TensorDesc** constructor returns an object of the **TensorDesc** type.

## Exception Handling

None

## Constraints

None
