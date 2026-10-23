# GetMin

## 函数功能

获取最小的T对象指针。

## 函数原型

```cpp
const T *GetMin() const
T *GetMin()
```

## 参数说明

无。

## 返回值说明

当最小值指针为nullptr时（例如默认构造Range对象或调用SetMin(nullptr)后），返回nullptr；否则返回指向最小T对象的指针。

## 约束说明

无。

## 调用示例

```cpp
int min = -1;
int max = 1024;
Range<int> range(&min, &max);

auto ret = range.GetMin(); // ret指针指向min
```
