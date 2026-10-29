# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:23:25.585Z pushedAt=2026-10-15T03:48:04.926Z -->

**OpContextBuilderBase** is the base class of each **ContextBuilder**. It is used to construct the operator information in the subclass **context**, including the operator type, name, input/output prototype count, input/output instance count, attributes, and other information.

The inheritance relationship of **OpContextBuilderBase** is as follows:

![opcontext_builder_base](../../figures/opcontext_builder_base.png)

> [!NOTE] Note
> The **OpContextBuilderBase** base class object cannot be constructed independently. It can only be constructed through a subclass.

## Header File to Include

```cpp
#include "base/context_builder/op_context_builder_base.h"
```
