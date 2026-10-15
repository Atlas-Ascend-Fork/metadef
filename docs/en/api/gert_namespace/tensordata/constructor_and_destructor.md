# Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:19:34.785Z pushedAt=2026-10-15T03:48:05.041Z -->

## Function

Constructs a **TensorData**.

Construction method 1: Specifies the address of the tensor data and the function **manager** used to manage the tensor data.

Construction method 2: Specifies the address of the tensor data, the function **manager** used to manage the tensor data, the memory size occupied by the tensor data, and the location (host or device) of the tensor data.

Construction method 3: Move construction form.

Note: If **manager** is **nullptr**, **addr** is considered the data address of the tensor. Otherwise, the data address of the tensor is provided by **manager**.

## Function Prototype

- Constructor

    ```cpp
    explicit TensorData(TensorAddress addr = nullptr, const TensorAddrManager manager = nullptr)
    explicit TensorData(TensorAddress addr, const TensorAddrManager manager, size_t size, TensorPlacement placement)
    TensorData(TensorData &&other) noexcept
    TensorData(const TensorData &) = delete
    ```

- Destructor

    ```cpp
    ~TensorData
    ```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|addr|Input|Address of the tensor data. using TensorAddress = void *;|
|manager|Input|Management function for the tensor data. If **manager** is null, **addr** is considered the data address of the tensor, and this data does not need to be released. using TensorAddrManager = ge::graphStatus (*)(TensorAddress addr, TensorOperateType operate_type, void **out);enum TensorOperateType {  kGetTensorAddress,  ///< Obtain the address of the tensor.    kFreeTensor,        ///< Free the tensor.    kPlusShareCount,    ///< Share the tensor.    kTensorOperateType};|
|size|Input|Memory size occupied by the tensor data.|
|placement|Input|Device location of the tensor data.|

## Return Value

Initialized **TensorData** object.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, HostAddrManager, 100U, kOnHost);
```
