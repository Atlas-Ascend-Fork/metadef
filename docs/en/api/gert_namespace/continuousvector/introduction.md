# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:42:20.134Z pushedAt=2026-10-15T03:48:04.854Z -->

This class is a POD class that stores description information and the actual data elements (whose type is specified by template parameter **T**) in a contiguous memory space. It does not support dynamic expansion.

The description information of this class includes the maximum number of elements that can be stored and the current number of actual elements stored.

## Header Files to Include

```cpp
#include <continuous_vector.h>
```
