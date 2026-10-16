# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:57:03.352Z pushedAt=2026-10-15T03:48:04.990Z -->

**RuntimeAttrs** is a class for accessing operator attributes, providing access to attributes during operator execution. This class provides a set of methods that allow users to obtain attribute values of different types by attribute index, such as **int64\_t**, **float**, **bool**, **string**, and **Tensor**. In **ExtendedKernelContext** and its subclasses, operator attributes can be obtained through the **GetAttrs** API, and the return value contains only the attributes defined in the IR prototype.

## Header File to Include

```cpp
#include <runtime_attrs.h>
```
