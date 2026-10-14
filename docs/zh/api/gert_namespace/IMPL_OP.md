# IMPL\_OP

## 产品支持情况

全量芯片支持。

## 头文件

\#include <register/op_impl_registry.h\>

## 功能说明

定义一个`static gert::OpImplRegisterV2`全局对象并完成构造，从而把`op_type`算子的`Host`侧实现（shape/datatype/range推导、Tiling、TilingParse、算子执行、私有属性等）注册到框架。

## 函数原型

```c++
IMPL_OP(op_type) IMPL_OP_COUNTER_NUMBER(op_type, op_impl_register_##op_type, __COUNTER__)
```

## 参数说明

| 参数名 | 输入/输出 | 描述 |
| --- | --- | --- |
| op_type | 输入 | 要注册的算子类型名。宏内用`#op_type`字符串化，同时用`##`拼接变量名，因此不能传字符串字面量、宏表达式或带`::`的限定名。需与算子原型注册（REG_OP/OP_ADD等）的`op type`完全一致。 |

## 返回值说明

无

## 约束说明

无
