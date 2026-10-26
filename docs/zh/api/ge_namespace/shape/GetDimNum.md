# GetDimNum

## 函数功能

获取Shape中有效维度的个数。

## 函数原型

```cpp
size_t GetDimNum() const
```

## 参数说明

无。

## 返回值

返回有效维度的个数。对于未知维度数Shape `{-2}`，返回0；此时 `GetDims().size()` 为1。判断标量应使用 `GetDims().size() == 0U`，避免将未知维度数误判为标量。

## 异常处理

无。

## 约束说明

无。
