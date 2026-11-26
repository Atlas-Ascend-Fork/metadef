# ResetData

## 函数功能

释放Tensor中数据内存。

ResetData(data, size, deleter_func)：使用调用方提供的数据内存重置Tensor数据。该高性能接口与[SetData](SetData.md)的区别是避免重复`make_shared`。

## 函数原型

```cpp
std::unique_ptr<uint8_t[], Tensor::DeleteFunc> ResetData()
graphStatus ResetData(uint8_t *data, size_t size, const Tensor::DeleteFunc &deleter_func)
```

## 参数说明

`ResetData()`无参数。带参数重载的参数如下：

|参数名|输入/输出|描述|
|--|--|--|
|data|输入|需设置的数据内存地址。|
|size|输入|数据的长度，单位为字节。|
|deleter_func|输入|用于释放`data`数据的删除器，类型为`Tensor::DeleteFunc`（`std::function<void(uint8_t *)>`）。|

## 返回值

`ResetData()`返回释放后的内存地址和删除器；带参数重载返回`graphStatus`类型，设置成功返回GRAPH\_SUCCESS，否则，返回GRAPH\_FAILED。

## 异常处理

无。

## 约束说明

调用带参数重载时，需保证传入内存只被当前Tensor使用，具有独占所有权。
