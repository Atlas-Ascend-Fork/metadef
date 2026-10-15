# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:23:14.584Z pushedAt=2026-10-15T03:48:05.050Z -->

## Function

Constructs the specified **Tensor** object. The **TensorV2** class describes the information and behavior of a **Tensor** object, including shape, data format, data type, stride, offset, and the tensor data content **tensordata**.

## Function Prototype

```cpp
TensorV2()   // Default constructor.
TensorV2 (const StorageShape &storage_shape, const StorageFormat &storage_format, const TensorPlacement placement, const ge::DataType data_type, TensorAddress addr)
TensorV2(const StorageShape &storage_shape, const StorageFormat &storage_format, ge::DataType data_type)
TensorV2(const StorageShape &storage_shape, const StorageFormat &storage_format, const TensorPlacement placement, const ge::DataType data_type, TensorAddress addr, TensorAddrManager manager)
TensorV2(const StorageShape &storage_shape, const StorageFormat &storage_format, const TensorPlacement placement, const ge::DataType data_type, TensorAddress addr, TensorAddrManager manager, const Stride &stride, const int64_t offset)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|storage_shape|Input|Specifies the shape information of the tensor. **StorageShape** type.|
|storage_format|Input|Specifies the data format information of the tensor. **StorageFormat** type.|
|placement|Input|Specifies the device location where the actual data of the tensor is stored. **TensorPlacement** type.|
|data_type|Input|Specifies the data type information of the tensor. **ge::DataType** type.|
|addr|Input|Specifies the memory address where the actual data of the tensor is stored. **TensorAddress** type, defined as follows: using TensorAddress = void *;|
|manager|Input|Management function for the tensor data. If **manager** is null, **addr** is considered the data address of the tensor, and this data does not need to be freed. using TensorAddrManager = ge::graphStatus (*)(TensorAddress addr, TensorOperateType operate_type, void **out);enum TensorOperateType {  kGetTensorAddress,  ///< Obtain the address of the Tensor.    kFreeTensor,        ///< Free the Tensor.    kPlusShareCount,    ///< Share the Tensor.    kTensorOperateType};|
|stride|Input|Specifies the stride information of the tensor. **Stride** type.|
|offset|Input|Specifies the offset information of the tensor. **int64_t** type.|

## Return Value

Returns an initialized **Tensor** object.

## Constraints

The values of the members in **Tensor** (such as **format**, **shape**, **stride**, and **offset**) must be explicitly set; otherwise, they are undefined.

The **TensorV2** class does not support graph compilation scenarios.

After a **TensorV2**-type pointer is converted to a **Tensor**-type pointer, the member functions of **Tensor** can be called.

Before converting a **Tensor**-type pointer to a **TensorV2**-type pointer, obtain the version number through **GetVersion\(\)**. Only **kTensorV2** can be converted.

## Example

```cpp
TensorV2 tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
                {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
                kFollowing,                                  // placement
                ge::DT_FLOAT16,                              //dt
                nullptr};
```
