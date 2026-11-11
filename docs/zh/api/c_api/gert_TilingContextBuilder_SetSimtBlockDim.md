# gert\_TilingContextBuilder\_SetSimtBlockDim

## 函数功能

使用OpTilingContextBuilder构造TilingContext时设置SIMT Block维度，与OpTilingContextBuilder::SimtBlockDim等价。本接口为弱符号桥接接口，使用C linkage（extern "C"）声明，但参数block_dim为C++类型gert::Dim3，因此仅支持在C++代码中调用。

## 函数原型

```cpp
uint32_t __attribute__((weak)) gert_TilingContextBuilder_SetSimtBlockDim(void *builder, const gert::Dim3 *block_dim)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|builder|输入|OpTilingContextBuilder指针。|
|block_dim|输入|SIMT Block维度。|

## 返回值说明

状态码，0表示设置成功。

## 约束说明

无。

## 调用示例

```cpp
OpTilingContextBuilder ctx_builder;
gert::Dim3 block_dim(2, 3);
auto ret = gert_TilingContextBuilder_SetSimtBlockDim(reinterpret_cast<void *>(&ctx_builder), &block_dim);
```
