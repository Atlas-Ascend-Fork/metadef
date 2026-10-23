# Operator Overload

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:23:18.861Z pushedAt=2026-10-15T03:48:04.693Z -->

For scenarios that require comparing the sizes of **AscendString** objects (for example, sorting the keys of a **map** data structure), this is implemented by overloading the following operators.

```cpp
  bool operator<(const AscendString& d) const;
  bool operator>(const AscendString& d) const;
  bool operator<=(const AscendString& d) const;
  bool operator>=(const AscendString& d) const;
  bool operator==(const AscendString& d) const;
  bool operator!=(const AscendString& d) const;
  bool operator==(const char_t *const d) const;
  bool operator!=(const char_t *const d) const;
```
