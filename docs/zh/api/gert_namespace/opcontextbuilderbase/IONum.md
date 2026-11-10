# IONum

## 函数功能

设置算子输入输出IR原型个数，用于构造各子类Context的ComputeNodeInfo信息。该接口默认每个IR原型输入输出的实例个数为1。

## 函数原型

```cpp
T &IONum(size_t input_ir_num, size_t output_ir_num)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|input_ir_num|输入|输入IR原型个数。|
|output_ir_num|输入|输出IR原型个数。|

## 返回值说明

返回子类对象T类型的引用，用于支持子类链式调用。

## 约束说明

- 若多次调用本接口或[IOInstanceNum](IOInstanceNum.md)，输入输出数量配置以最后一次调用为准。
- 应先通过`IONum()`或`IOInstanceNum()`确定输入输出数量，再设置Tensor及其描述。传入Tensor后，不得再修改输入输出数量配置；如需修改，应创建新的Builder。
