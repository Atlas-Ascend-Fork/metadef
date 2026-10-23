# IMPL\_OP

<!-- md-trans-meta sourceCommit=000cd91b8f809ac55f4c51bd9fdee3ace8db1589 translatedAt=2026-10-16T01:51:13.235Z pushedAt=2026-10-16T01:59:37.418Z -->

## Supported Products

Supported on all chips.

## Header File

\#include <register/op_impl_registry.h\>

## Description

Defines a global `gert::OpImplRegisterV2` object and completes its construction, thereby registering the `Host`-side implementation of the `op_type` operator (such as shape/datatype/range inference, Tiling, TilingParse, operator execution, and private attributes) with the framework.

## Function Prototype

```c++
IMPL_OP(op_type) IMPL_OP_COUNTER_NUMBER(op_type, op_impl_register_##op_type, __COUNTER__)
```

## Parameters

| Parameter | Input/Output | Description |
| --- | --- | --- |
| op_type | Input | Name of the operator type to register. The macro stringifies it with `#op_type` and concatenates variable names with `##`, so it cannot be a string literal, a macro expression, or a qualified name containing `::`. It must be exactly the same as the `op type` used in operator prototype registration (such as **REG_OP**/**OP_ADD**). |

## Return Value

None

## Constraints

None
