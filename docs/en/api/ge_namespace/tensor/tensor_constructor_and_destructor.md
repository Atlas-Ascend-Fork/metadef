# Tensor Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:01:03.348Z pushedAt=2026-10-15T03:48:04.757Z -->

## Function

Tensor constructor and destructor.

## Function Prototype

```cpp
Tensor()
~Tensor() = default
explicit Tensor(const TensorDesc &tensor_desc)
Tensor(const TensorDesc &tensor_desc, const std::vector<uint8_t> &data)
Tensor(const TensorDesc &tensor_desc, const uint8_t *data, size_t size)
Tensor(TensorDesc &&tensor_desc, std::vector<uint8_t> &&data)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|tensor_desc|Input|**TensorDesc** object, the tensor descriptor to be set.|
|data|Input|Data to be set.|
|size|Input|Length of the data, in bytes.|

## Return Value

The tensor constructor returns a tensor object.

## Exception Handling

None

## Constraints

None
