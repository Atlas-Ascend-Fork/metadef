# RegOpLibInit

<!-- md-trans-meta sourceCommit=21edba955d3763e74f48b491a55c2a66ccde83c9 translatedAt=2026-10-16T01:37:58.304Z pushedAt=2026-10-16T02:00:17.874Z -->

## Function

Registers the initialization function of a custom operator dynamic library.

## Header File to Include

```cpp
#include <register/op_lib_register.h>
```

This header file is installed by the GE (Graph Engine) component to `${INSTALL_DIR}/include/register/` along with CANN Toolkit, and it is not a header file in the metadef repository source code. The `REGISTER_OP_LIB` macro is provided by this header file.

## Function Prototype

```cpp
OpLibRegister &RegOpLibInit(OpLibInitFunc func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**func**|Input|Custom initialization function to be registered, of type **OpLibInitFunc**. using OpLibInitFunc = uint32_t (*)(ge::AscendString&);|

## Return Value

Returns an **OpLibRegister** object that newly registers the **OpLibInitFunc** function **func**.

## Constraints

This is an internal associated API used by the custom operator project framework to register the initialization function of a custom operator dynamic library. Operator developers do not need to be concerned with it.

## Example

```cpp
uint32_t Init(ge::AscendString&) {
  // init func
  return 0;
}

REGISTER_OP_LIB(vendor_1).RegOpLibInit(Init); // Register the initialization function Init for the vendor named vendor_1.
```
