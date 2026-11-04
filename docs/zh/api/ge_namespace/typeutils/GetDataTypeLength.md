# GetDataTypeLength

## 函数功能

获取数据类型所占内存大小。

使用该接口需要包含type\_utils.h头文件。

```cpp
#include "graph/utils/type_utils.h"
```

## 函数原型

```cpp
static bool GetDataTypeLength(const ge::DataType data_type, uint32_t &length)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|data_type|输入|数据类型。|
|length|输出|对于普通数据类型，返回每个元素所占内存大小，单位：字节；对于DT_INT1、DT_INT4、DT_UINT1等bit类型，返回1000与bit数相加得到的编码值（即1000+bit数），而非每个元素的字节数。需要计算元素总字节数时，建议使用GetSizeInBytes接口，不要直接将该编码值当作字节数使用。|

## 返回值说明

获取成功时返回true；data\_type不支持时返回false。

## 约束说明

无。

## 调用示例

```cpp
uint32_t type_length;
ge::DataType data_type = ge::DT_INT8;
const bool ret = ge::TypeUtils::GetDataTypeLength(data_type, type_length); // type_length 1
if (!ret) {
  // ...
}
```
