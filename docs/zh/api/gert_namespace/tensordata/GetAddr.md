# GetAddr

## 函数功能

获取tensor数据地址。若存在manager函数，则由manager函数给出地址。

## 函数原型

```cpp
TensorAddress GetAddr() const
```

## 参数说明

无。

## 返回值说明

tensor地址。
manager 地址查询回调返回非 `ge::GRAPH_SUCCESS` 时，返回 `nullptr`；回调成功时，返回回调设置的地址。

## 约束说明

无。

## 调用示例

```cpp
auto addr = reinterpret_cast<void *>(0x10);
TensorData td(addr, nullptr);
auto addr = td.GetAddr(); // 0x10
```
