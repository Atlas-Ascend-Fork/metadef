# gert\_TilingContextBuilder\_SetSimtGridDim

## 函数功能

使用OpTilingContextBuilder构造TilingContext时设置SIMT Grid维度，与OpTilingContextBuilder::SimtGridDim等价。本接口为弱符号桥接接口，使用C linkage（extern "C"）声明，但参数 `grid_dim` 为C++类型 `gert::Dim3`，因此仅支持在C++代码中调用，不属于可由C源码直接调用的纯C API。

## 函数原型

```cpp
uint32_t __attribute__((weak)) gert_TilingContextBuilder_SetSimtGridDim(void *builder, const gert::Dim3 *grid_dim)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|builder|输入|OpTilingContextBuilder指针。|
|grid_dim|输入|SIMT Grid维度。|

## 返回值说明

状态码，0表示设置成功。

## 约束说明

无。

## 调用示例

```cpp
// C++ 示例：本接口的原型使用 gert::Dim3。
OpTilingContextBuilder ctx_builder;
gert::Dim3 grid_dim(4, 5);
auto ret = gert_TilingContextBuilder_SetSimtGridDim(reinterpret_cast<void *>(&ctx_builder), &grid_dim);
```
