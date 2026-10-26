# GetC0Value

## 函数功能

从实际format中解析出C0 format信息。

## 函数原型

```cpp
inline int64_t GetC0Value(int32_t format)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|format|输入|实际format（4字节大小，第1个字节的高四位为预留字段，低四位为C0 format，第2-3字节为子format信息，第4字节为主format信息）。|

## 返回值

- 如果包含C0 format，提取编码字段值 `x` 并返回对应的 C0 值 `2^(x-1)`；例如字段值 `5` 返回 `16`。
- 如果不包含C0 format，返回-1。

## 异常处理

无。

## 约束说明

设置实际format格式时，第一个字节低四位的C0 format字段值 `x` 范围为1至15；`GetC0Value` 返回 `2^(x-1)`。未设置C0 format时返回-1。
