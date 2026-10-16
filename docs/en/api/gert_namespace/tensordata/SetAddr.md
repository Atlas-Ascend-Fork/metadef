# SetAddr

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:21:50.418Z pushedAt=2026-10-15T03:48:05.047Z -->

## Function

Sets the tensor address.

## Function Prototype

```cpp
ge::graphStatus SetAddr(const ConstTensorAddressPtr addr, TensorAddrManager manager)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|addr|Input|Tensor address. using ConstTensorAddressPtr = const void *;|
|manager|Input|Tensor management function. using TensorAddrManager = ge::graphStatus (*)(TensorAddress addr, TensorOperateType operate_type, void **out);|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success; otherwise, returns the error code defined in the **manager** management function.

## Constraints

None

## Example

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
td.SetAddr(addr, HostAddrManager);
```
