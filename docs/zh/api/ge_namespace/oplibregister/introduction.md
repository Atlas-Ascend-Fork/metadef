# 简介

OpLibRegister类所提供的接口为内部关联接口，当前主要为自定义算子动态库提供注册功能，供自定义算子工程框架注册指定初始化函数，开发者无需关注。

## 需要包含的头文件

```cpp
#include <register/op_lib_register.h>
```

该头文件由GE（Graph Engine）组件随CANN Toolkit安装到`${INSTALL_DIR}/include/register/`，不属于metadef仓库源码中的头文件。`REGISTER_OP_LIB`宏由该头文件提供。
