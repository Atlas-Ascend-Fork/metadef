# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:30:01.923Z pushedAt=2026-10-15T03:48:04.937Z -->

**OpImplRegisterV2** is an operator implementation registration utility class used for custom operator development. It supports the following features:

- Registers the shape inference, data type inference, and range inference implementations of an operator.
- Registers the Tiling computation implementation of an operator.
- Registers the attribute information of an operator.
- Specifies the input indexes that the shape inference and Tiling computation depend on.

During custom operator development, this class is used indirectly when users register an operator prototype based on **OP\_ADD**.

## Header File to Include

```cpp
#include "register/op_impl_registry.h"
```
