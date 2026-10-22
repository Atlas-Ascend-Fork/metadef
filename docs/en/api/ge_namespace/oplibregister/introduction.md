# Introduction

<!-- md-trans-meta sourceCommit=21edba955d3763e74f48b491a55c2a66ccde83c9 translatedAt=2026-10-16T01:37:51.800Z pushedAt=2026-10-16T02:00:17.874Z -->

The APIs provided by the **OpLibRegister** class are internal associated APIs. Currently, they mainly provide registration for custom operator dynamic libraries, allowing the custom operator project framework to register specified initialization functions. Developers do not need to pay attention to this.

## Header File to Include

```cpp
#include <register/op_lib_register.h>
```

This header file is installed by the GE (Graph Engine) component to `${INSTALL_DIR}/include/register/` along with CANN Toolkit, and it is not a header file in the metadef repository source code. The `REGISTER_OP_LIB` macro is provided by this header file.
