# GetCompileInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:34:29.351Z pushedAt=2026-10-15T03:48:05.074Z -->

## Function

Obtains **CompileInfo**.

This method obtains the compilation information parsed by the operator **TilingParse**. For details, see the **CompileInfo** structure corresponding to the specific operator. For example, the compilation information of the Add operator is as follows:

```cpp
struct AddCompileInfo {
  int64_t a;  // Input a.
  int64_t b;  // Input b.
};
```

## Function Prototype

```cpp
template<typename T> const T *GetCompileInfo() const

const void *GetCompileInfo() const
```

## Parameters

|Parameter|Description|
|--|--|
|T|Template parameter, which is of the **CompileInfo** type.|

## Return Value

**template\<typename T\> const T \*GetCompileInfo\(\) const;** Returns a pointer to a **CompileInfo** of the specified type **T**.

**const void \*GetCompileInfo\(\) const;** Returns a pointer to a **CompileInfo** of any type.

## Constraints

None

## Example

```cpp
ge::graphStatus TilingForAdd(TilingContext *context) {
  auto ci = context->GetCompileInfo<AddCompileInfo>();
  GE_ASSERT_NOTNULL(ci);
  ...
}
```
