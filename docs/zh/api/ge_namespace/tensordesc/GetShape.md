# GetShape

## 函数功能

获取TensorDesc所描述Tensor的Shape。

## 函数原型

```cpp
Shape GetShape() const
```

## 参数说明

无。

## 返回值

[Shape](../shape/Shape.md)类型，TensorDesc描述的Shape。

## 异常处理

无。

## 约束说明

返回的 `Shape` 对象与 `TensorDesc` 中保存的 Shape 共享底层维度信息。通过返回对象调用 `Shape::SetDim()` 会修改 `TensorDesc` 中的 Shape。

如果需要独立修改 Shape，假设 `desc` 为已有的 `TensorDesc`，可根据维度值构造新的 `Shape` 对象：

```cpp
ge::Shape shape(desc.GetShape().GetDims());
shape.SetDim(0, 7);  // 不会修改 desc 中的 Shape
```
