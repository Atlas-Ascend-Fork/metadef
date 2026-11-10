# IOInstanceNum

## 函数功能

当输入IR原型实例个数不为1时（一般是可选输入或动态输入场景），需要设置算子每个输入IR原型的实例个数，用于构造各子类Context的ComputeNodeInfo信息。

## 函数原型

```cpp
T &IOInstanceNum(const std::vector<uint32_t> &input_instance_num, const std::vector<uint32_t> &output_instance_num)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|input_instance_num|输入|是一个vector数组输入，vector的size代表算子原型输入个数，vector数组上每个位置的数字代表每个IR原型输入的实例个数。|
|output_instance_num|输入|是一个vector数组输入，vector的size代表算子原型输出个数，vector数组上每个位置的数字代表每个IR原型输出的实例个数。|

## 返回值说明

返回子类对象T类型的引用，用于支持子类链式调用。

## 约束说明

- 若多次调用本接口或[IONum](IONum.md)，输入输出数量配置以最后一次调用为准。
- 应先通过`IONum()`或`IOInstanceNum()`确定输入输出数量，再设置Tensor及其描述。传入Tensor后，不得再修改输入输出数量配置；如需修改，应创建新的Builder。
