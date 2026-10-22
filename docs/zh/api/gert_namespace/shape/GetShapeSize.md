# GetShapeSize

## 函数功能

获取Shape中所有维度大小的累乘结果。

## 函数原型

```cpp
int64_t GetShapeSize() const
```

## 参数说明

无。

## 返回值

返回所有维度大小的累乘结果；如果计算过程中发生乘法溢出，返回`kInvalidDimValue`（`INT64_MIN`）。

## 约束说明

无。
