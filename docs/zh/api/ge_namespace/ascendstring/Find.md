# Find

## 函数功能

查找子串在当前字符串中的位置。

## 函数原型

```cpp
size_t Find(const AscendString &ascend_string) const
```

## 约束说明

无。

## 参数说明

|参数名|输入/输出|描述|
|--|--|--|
|ascend_string|输入|要查找的子串。|

## 返回值

找到时返回子串的起始位置；未找到时返回 `std::string::npos`。默认构造的 `AscendString` 对象参与搜索时也返回 `std::string::npos`。
