# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:58:30.098Z pushedAt=2026-10-15T03:48:04.993Z -->

The **Shape** structure is used to describe the shape of a tensor and contains two pieces of information:

```cpp
size_t dim_num_;
int64_t dims_[kMaxDimNum];
```

Where, **dim\_num\_** indicates the number of dimensions of the shape, and **dims\_ array** indicates the specific shape of the tensor.

```cpp
size_t kMaxDimNum = 25;
```

**kMaxDimNum** indicates the maximum number of dimensions that can be supported (this value is the maximum supported specification; the actual support depends on the specific operator).

## Required Header File

```cpp
#include <shape.h>
```
