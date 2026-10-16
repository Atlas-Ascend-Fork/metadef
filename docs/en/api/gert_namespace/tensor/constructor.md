# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:10:38.053Z pushedAt=2026-10-15T03:48:05.020Z -->

## Function

Constructs a specified **Tensor** object. The **Tensor** class describes the information and behavior of a tensor object, including shape information, format information, datatype information, and the tensor data content **tensordata**.

## Function Prototype

```cpp
Tensor()   // Default constructor.
Tensor (const StorageShape &storage_shape, const StorageFormat &storage_format, const TensorPlacement placement, const ge::DataType data_type, TensorAddress addr)
Tensor(const StorageShape &storage_shape, const StorageFormat &storage_format, ge::DataType data_type)
Tensor(const StorageShape &storage_shape, const StorageFormat &storage_format, const TensorPlacement placement, const ge::DataType data_type, TensorAddress addr, TensorAddrManager manager)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|storage_shape|Input|Specifies the shape information of the tensor. **StorageShape** type.|
|storage_format|Input|Specifies the format information of the tensor. **StorageFormat** type.|
|placement|Input|Specifies the device location where the actual data of the tensor is stored. **TensorPlacement** type.|
|data_type|Input|Specifies the datatype information of the tensor. **ge::DataType** type.|
|addr|Input|Specifies the memory address where the actual data of the tensor is stored. **TensorAddress** type, defined as follows: using TensorAddress = void *;|
|manager|Input|Management function for tensor data. If **manager** is null, **addr** is considered the data address of the tensor, and this data does not need to be released. using TensorAddrManager = ge::graphStatus (*)(TensorAddress addr, TensorOperateType operate_type, void **out);enum TensorOperateType {  kGetTensorAddress,  ///< Obtain the address of the tensor.    kFreeTensor,        ///< Free the tensor.    kPlusShareCount,    ///< Share the tensor.    kTensorOperateType};|

## Return Value

Returns an initialized **Tensor** object.

## Constraints

The values of the members in **Tensor** (such as **format** and **shape**) must be explicitly set; otherwise, they are undefined.

## Example

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
              kFollowing,                                  // placement
              ge::DT_FLOAT16,                              //dt
              nullptr};
```
