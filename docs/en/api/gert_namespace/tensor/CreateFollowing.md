# CreateFollowing

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:10:39.336Z pushedAt=2026-10-15T03:48:05.022Z -->

## Function

Creates a **Tensor** with a specified data type and size, with its data laid out contiguously after the **Tensor** object.

## Function Prototype

- Creates a **Tensor** by passing the number of elements and the data type.

  ```cpp
  static std::unique_ptr<uint8_t[]> CreateFollowing(const int64_t shape_size, const ge::DataType dt, size_t &total_size)
  ```

- Creates a **Tensor** by passing the data type and the tensor length.

  ```cpp
  static std::unique_ptr<uint8_t[]> CreateFollowing(const ge::DataType dt, const size_t tensor_size, size_t &total_size)
  ```

## Parameters

**Table 1** Parameter description (creating a tensor by passing the number of elements and the data type)

|Parameter|Input/Output|Description|
|--|--|--|
|shape_size|Input|Number of elements.|
|dt|Input|Data type, of the **DataType** type.|
|total_size|Output|Length of the created tensor in memory, including the length of the tensor object and the length of the tensor data.|

**Table 2** Parameter description (creating a tensor by passing the data type and the tensor length)

|Parameter|Input/Output|Description|
|--|--|--|
|dt|Input|Data type, of the **DataType** type.|
|tensor_size|Input|Length of the tensor data, in bytes.|
|total_size|Output|Length of the created tensor in memory. Unlike the **tensor_size** parameter, **total_size** includes the length of the tensor object and the length of the tensor data, in bytes.|

## Return Value

Created **Tensor** pointer.

## Constraints

None

## Example

```cpp
size_t total_size;
auto tensor_holder = Tensor::CreateFollowing(shape_size, tensor_desc.GetDataType(), total_size);
```
