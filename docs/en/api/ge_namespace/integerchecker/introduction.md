# Introduction

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:25:05.492Z pushedAt=2026-10-15T03:48:04.697Z -->

**IntegerChecker** is a template class with the template parameter **T**, used to check whether an integer is within the valid range of the specified data type **T**.

## Header Files to Include

```cpp
#include <extern_math_util.h>
```

## Public Member Functions

```cpp
template<typename T>
class IntegerChecker {
 public:
  template<typename T1>
  static bool Compat(const T1 v) {
  // Specific implementation.
  }
};
```
