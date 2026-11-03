# CreateCap

## 函数功能

根据指定的最大容量创建一个TilingData类实例。

## 函数原型

```cpp
static std::unique_ptr<uint8_t[]> CreateCap(const size_t cap_size)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|cap_size|输入|最大容量，单位为字节。|

## 返回值说明

`std::unique_ptr<uint8_t[]>`类型的缓冲区持有者，拥有创建的实例所在的连续内存缓冲区，TilingData实例位于缓冲区起始处。调用方需要通过持有者的get()获取缓冲区地址并转换为TilingData指针使用，实例在持有者生命周期内有效。

## 约束说明

无。

## 调用示例

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());
```
