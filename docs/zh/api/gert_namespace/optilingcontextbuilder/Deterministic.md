# Deterministic

## 函数功能

设置是否开启确定性计算。

## 函数原型

```cpp
OpTilingContextBuilder &Deterministic(int32_t deterministic)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|deterministic|输入|是否开启确定性计算（1为开启，0为关闭）。|

## 返回值说明

OpTilingContextBuilder对象本身，用于链式调用。

## 约束说明

- 如果未调用本接口，确定性计算默认为关闭（**0**）。
- 通过指针传入的参数（void\*），其内存所有权归调用者所有；调用者必须确保指针在ContextHolder对象的生命周期内有效。
