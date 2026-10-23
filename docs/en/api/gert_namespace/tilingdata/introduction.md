# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:58:56.396Z pushedAt=2026-10-15T03:48:05.115Z -->

**TilingData** is used to store the tiling computation result of an operator, that is, the parameters related to the data splitting algorithm determined by the tiling implementation based on information such as the operator's **shape** (for example, the size of each data block to be moved, and the number of loop iterations for the move and compute operations).

## Header File to Include

```cpp
#include <tiling_data.h>
```
