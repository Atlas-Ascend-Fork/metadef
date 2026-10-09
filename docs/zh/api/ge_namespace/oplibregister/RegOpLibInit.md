# RegOpLibInit

## 函数功能

注册自定义算子动态库的初始化函数。

## 需要包含的头文件

```cpp
#include <register/op_lib_register.h>
```

该头文件由GE（Graph Engine）组件随CANN Toolkit安装到`${INSTALL_DIR}/include/register/`，不属于metadef仓库源码中的头文件。`REGISTER_OP_LIB`宏由该头文件提供。

## 函数原型

```cpp
OpLibRegister &RegOpLibInit(OpLibInitFunc func)
```

## 参数说明

|参数|输入/输出|说明|
|--|--|--|
|**func**|输入|要注册的自定义初始化函数，类型为OpLibInitFunc。using OpLibInitFunc = uint32_t (*)(ge::AscendString&);|

## 返回值说明

返回一个OpLibRegister对象，该对象新增注册了OpLibInitFunc函数func。

## 约束说明

该接口为内部关联接口，供自定义算子工程框架注册自定义算子动态库的初始化函数使用，算子开发者无需关注。

## 调用示例

```cpp
uint32_t Init(ge::AscendString&) {
  // init func
  return 0;
}

REGISTER_OP_LIB(vendor_1).RegOpLibInit(Init); // 注册厂商名为vendor_1的初始化函数Init
```
