# GetAddr

## 函数功能

获取Tensor的数据地址。

## 函数原型

```cpp
const void *GetAddr() const
void *GetAddr()
```

## 参数说明

无。

## 返回值说明

返回数据地址。

## 约束说明

无。

## 调用示例

```cpp
float data = 0.0F;
Tensor tensor{{{1}, {1}},                              // shape
              {ge::FORMAT_ND, ge::FORMAT_ND, {}},      // format
              kOnHost,                                 // placement
              ge::DT_FLOAT,                            // dt
              &data};
auto addr = tensor.GetAddr(); // &data
```
