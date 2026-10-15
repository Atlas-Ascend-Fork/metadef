# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:08:01.102Z pushedAt=2026-10-15T03:48:05.016Z -->

The **Stride** structure describes the stride of a tensor and contains two pieces of information:

```cpp
size_t dim_num_;
int64_t strides_[kMaxDimNum];
```

Where, **dim\_num\_** indicates the number of dimensions of the stride, which is consistent with the number of dimensions describing the tensor, and the **strides\_ array** indicates the stride of each dimension of the tensor.

```cpp
size_t kMaxDimNum = 25;
```

**kMaxDimNum** indicates the maximum number of dimensions supported (this value is the maximum supported specification; the actual support depends on the specific operator).

> [!NOTE] Note
> This API is reserved for future functionality and is not supported in the current version.

## Header File to Include

```cpp
#include <stride.h>
```
