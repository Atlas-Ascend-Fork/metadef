# ShareFrom

## 函数功能

使当前的TensorData对象共享另一个对象的内存以及内存管理函数。

当当前对象尚未与 `other` 共享，且 `other` 使用非空管理函数时，本接口会调用该管理函数的 `kPlusShareCount` 操作增加共享引用。若 `other` 的管理函数为空，则只共享地址和元数据，不执行共享计数回调。

## 函数原型

```cpp
ge::graphStatus ShareFrom(const TensorData &other)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|other|输入|另一个TensorData对象。|

## 返回值说明

成功时返回ge::GRAPH\_SUCCESS。若释放当前对象已有数据失败，或 `kPlusShareCount` 操作失败，则返回对应管理函数的错误状态。共享计数操作失败时，本对象不保留从 `other` 复制的地址、管理函数及元数据。

## 约束说明

当 `other` 使用非空管理函数时，该函数应支持 `kPlusShareCount` 操作，以便 `ShareFrom` 获取共享引用。

## 调用示例

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td1(addr, HostAddrManager, 100U, kOnHost);
TensorData td2(addr, nullptr);
td2.ShareFrom(td1);
```
