# TensorDescInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:18:44.569Z pushedAt=2026-10-15T03:48:04.684Z -->

```cpp
    struct TensorDescInfo {
        Format format_ = FORMAT_RESERVED;        /* tbe op register support format */
        DataType dataType_ = DT_UNDEFINED;       /* tbe op register support datatype */
    };
```

**Format** is an enumeration type. For its definition, see [Format](Format.md).

**DataType** is an enumeration type. For its definition, see [DataType](DataType.md).
