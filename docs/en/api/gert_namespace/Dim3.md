# Dim3

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:20:36.860Z pushedAt=2026-10-15T03:48:04.783Z -->

The **Dim3** structure is defined as follows:

```cpp
struct Dim3 {
  uint32_t x, y, z;
  Dim3(const uint32_t dim3_x, const uint32_t dim3_y = 1, const uint32_t dim3_z = 1) : x(dim3_x), y(dim3_y), z(dim3_z) {
  }
};
```

**Dim3** is a structure that contains three **uint32** fields: **x**, **y**, and **z**. In SIMT, it can represent the number of threads of a thread block in the x, y, and z dimensions, or the number of thread blocks of a grid in the x, y, and z dimensions.
