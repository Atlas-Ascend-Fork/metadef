# Add

## 函数功能

新增一个ContinuousVector元素，其中新增ContinuousVector元素的容量为inner\_vector\_capacity。

## 函数原型

```cpp
template<typename T> ContinuousVector *Add(size_t inner_vector_capacity)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|inner_vector_capacity|输入|新增ContinuousVector元素的容量。|

## 返回值说明

新增ContinuousVector元素的首地址。
容量已满或计算内层向量长度时发生整数溢出则返回 `nullptr`；调用方应检查返回值后再访问新增元素。

## 约束说明

新增元素数量不能超过初始化时设置的容量；容量耗尽后不能继续添加。

## 调用示例

```cpp
// 创建ContinuousVectorVector对象cvv
...
// 增加元素
size_t inner_vector_capacity = 2;
auto cv = cvv->Add<float>(inner_vector_capacity);
```
