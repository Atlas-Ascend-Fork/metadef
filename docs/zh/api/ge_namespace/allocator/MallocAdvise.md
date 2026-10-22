# MallocAdvise

## 函数功能

在用户内存池中根据指定size大小申请device内存，建议申请的内存地址为addr。

## 函数原型

```cpp
virtual MemBlock *MallocAdvise(size_t size, void *addr)
```

## 参数说明

|参数名|输入/输出|描述|
|--|--|--|
|size|输入|指定需要申请内存大小。|
|addr|输入|建议申请的内存地址为addr。|

## 返回值

返回[MemBlock](../memblock/MemBlock.md)指针。

## 异常处理

无。

## 约束说明

默认实现忽略`addr`，并将`size`传给[Malloc](Malloc.md)。若需自定义建议地址的处理方式，可在派生类中重写此接口。
