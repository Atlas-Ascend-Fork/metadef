# IsExpandIndex

## 函数功能

基于补维后的shape，判断指定的index轴是否为补维轴。

## 函数原型

```cpp
bool IsExpandIndex(const AxisIndex index) const
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|index|输入|指定轴的索引。|

## 返回值说明

- true代表指定的轴为补维轴。
- false代表指定的轴为原始轴。

## 约束说明

index的有效范围为[0, kMaxExpandSize)，kMaxExpandSize为56。调用方需要保证index在有效范围内。

## 约束说明

无。

## 调用示例

```cpp
ExpandDimsType type1("1001");
bool is_expand_index0 = type1.IsExpandIndex(0); // true
bool is_expand_index1 = type1.IsExpandIndex(1); // false
```
