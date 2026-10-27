# TilingData

## 函数功能

设置算子的TilingData指针，用于算子Tiling计算时，向该指针中写入TilingData数据。

## 函数原型

```cpp
OpTilingContextBuilder &TilingData(const gert::TilingData *tiling_data, gert::Chain::Deleter deleter = nullptr)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|tiling_data|输入|TilingData数据指针。|
|deleter|输入|Tiling数据的删除器，如果用户显式传入删除器deleter，ContextHolder析构时会调用删除器释放Tiling数据，默认不传入。建议使用TilingDataSize接口。|

## 返回值说明

OpTilingContextBuilder对象本身，用于链式调用。

## 约束说明

- 在调用Build方法之前，必须设置TilingData或TilingDataSize，否则构造出的TilingContext将包含未定义数据。
- 未传入deleter时，tiling_data为借用指针，内存由调用者管理；调用者须确保其在ContextHolder生命周期内有效，并在Holder销毁前不释放该内存。
- 显式传入deleter时，ContextHolder负责调用该删除器释放tiling_data，调用者不得再自行释放同一对象。若在Build前再次设置TilingData或TilingDataSize，旧指针对应的非空deleter会在替换时调用。
