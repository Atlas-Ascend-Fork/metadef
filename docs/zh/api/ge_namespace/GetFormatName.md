# GetFormatName

## 函数功能

根据传入的Format类型，获取Format的字符串描述。

## 函数原型

```cpp
const char_t *GetFormatName(Format format)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|format|输入|Format枚举值。|

## 返回值

该Format所对应的字符串描述。对于未识别的格式或大于等于 `FORMAT_END` 的值，返回 `"UNKNOWN"`；函数不会返回 `nullptr`。

## 异常处理

无。

## 约束说明

返回的字符串不可被修改。
