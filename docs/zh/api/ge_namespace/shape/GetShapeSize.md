# GetShapeSize

## 函数功能

获取Shape中所有dim的累乘结果。

## 函数原型

```cpp
int64_t GetShapeSize() const
```

## 参数说明

无。

## 返回值
返回Shape各维的乘积，特殊情况如下：

- 维度值中包含 `-1`（`ge::UNKNOWN_DIM`）或 `-2`（`ge::UNKNOWN_DIM_NUM`）时，返回 `-1`，表示shape未知。
- 维度值中包含 `0` 时，返回 `0`，表示空tensor。
- 维度数量为 `0` 时，返回 `0`，表示标量。
- 维度乘积发生 `int64_t` 溢出时，返回 `0`。
- 其他情况返回维度值的乘积。

## 异常处理

无。

## 约束说明

无。
