# GetOutputInstanceInfo

## 函数功能

根据算子IR原型中的输出索引，获取对应的实例化对象。

## 函数原型

```cpp
const AnchorInstanceInfo *GetOutputInstanceInfo(const size_t ir_index) const
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|ir_index|输入|算子IR原型定义中的输出索引，从0开始计数。|

## 返回值说明

当ir_index小于GetIrOutputsNum()时，返回对应实例化信息的指针；否则返回nullptr。调用方使用前应检查指针是否为空。

## 约束说明

无。

## 调用示例

```cpp
for (size_t i = 0; i < ir_outputs.size(); ++i) {
  auto ins_info = compute_node_info.GetOutputInstanceInfo(i);
  ...
}
```
