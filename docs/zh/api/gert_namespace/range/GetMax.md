# GetMax

## 函数功能

获取最大的T对象指针。

## 函数原型

```cpp
const T *GetMax() const
T *GetMax()
```

## 参数说明

无。

## 返回值说明

当最大值指针为nullptr时（例如默认构造Range对象或调用SetMax(nullptr)后），返回nullptr；否则返回指向最大T对象的指针。

## 约束说明

调用方在解引用返回指针前需要检查其是否为nullptr。

## 调用示例

```cpp
int min = -1;
int max = 1024;
gert::Range<int> range(&min, &max);

auto ret = range.GetMax(); // ret指针指向max
```
