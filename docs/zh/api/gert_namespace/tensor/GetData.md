# GetData

## 函数功能

获取Tensor的数据地址。

## 函数原型

```cpp
template<class T>  const T *GetData() const
template<class T>  auto GetData() -> T*
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|T|输入|数据类型。|

## 返回值说明

数据地址。

## 约束说明

无。

## 调用示例

```cpp
float data = 0.0F;
Tensor tensor{{{1}, {1}},                         // shape
              {ge::FORMAT_ND, ge::FORMAT_ND, {}}, // format
              kOnHost,                            // placement
              ge::DT_FLOAT,                       // dt
              &data};
auto addr = tensor.GetData<float>(); // &data
```
