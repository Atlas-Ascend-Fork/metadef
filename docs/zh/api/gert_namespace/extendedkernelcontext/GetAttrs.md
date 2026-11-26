# GetAttrs

## 函数功能

获取算子的属性值，仅在算子IR原型定义中的属性值会被返回，其他属性值被丢弃。

## 函数原型

```cpp
const RuntimeAttrs *GetAttrs() const
```

## 参数说明

无。

## 返回值说明

返回指向const RuntimeAttrs对象的指针，其中包含所有IR原型定义的属性值，属性值按照IR原型定义的顺序依次保存。若底层KernelContext未关联计算节点信息，则返回nullptr。

## 约束说明

解引用返回指针前必须检查其是否为nullptr。该指针由底层Context持有，仅在底层Context有效期间保持有效。

## 调用示例

```cpp
#include <exe_graph/runtime/extended_kernel_context.h>

void ReadAttrs(gert::KernelContext *context) {
  auto extend_context = reinterpret_cast<gert::ExtendedKernelContext *>(context);
  const auto *rt_attrs = extend_context->GetAttrs();
  if (rt_attrs == nullptr) {
    return;
  }
  // 在context有效期间使用rt_attrs。
}
```
