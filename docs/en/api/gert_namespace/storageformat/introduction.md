# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:02:49.019Z pushedAt=2026-10-15T03:48:05.002Z -->

**StorageFormat** is a management class for operator data storage formats. It is used to express tensor formats and record the dimension expansion rules for conversions between different formats. This class mainly stores:

- Original format: the original format of the tensor at input time;
- Runtime format: the format actually used during computation;
- Dimension expansion rules: records the shape dimension expansion rules when the original format is converted to the runtime format.

## Header File to Include

```cpp
#include <storage_format.h>
```
