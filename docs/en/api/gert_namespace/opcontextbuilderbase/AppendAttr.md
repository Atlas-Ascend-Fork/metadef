# AppendAttr

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:22:58.807Z pushedAt=2026-10-15T03:48:04.925Z -->

## Function

Appends attribute information to the IR prototype of an operator, with subscripts starting from 0. It is used to construct the **ExtendedInfo** information in the **ExtendedKernelContext** base class of each subclass **Context**.

After construction is complete, the order of attributes in **RuntimeAttrs** obtained through the base class API **GetAttr** of **Context** is consistent with the order in which they were appended during construction.

For example:

```cpp
bool attr0 = true;
int64_t attr1 = 1;
vector<int64_t> attr2 = {1, 2, 3, 4};
context_builder.AppendAttr(attr0).AppendAttr(attr1).AppendAttr(attr2);
```

After the build construction is complete, the result is as follows:

```cpp
ctx->GetAttrs()->GetBool(0) -> attr0,
ctx->GetAttrs()->GetInt(1) -> attr1,
ctx->GetAttrs()->GetListInt(2) -> attr2
```

## Function Prototype

```cpp
T &AppendAttr(bool attr)
T &AppendAttr(int64_t attr)
T &AppendAttr(float attr)
T &AppendAttr(const ge::AscendString &attr)
T &AppendAttr(const std::vector<bool> &attr)
T &AppendAttr(const std::vector<int64_t> &attr)
T &AppendAttr(const std::vector<float> &attr)
T &AppendAttr(const std::vector<ge::AscendString> &attr)
T &AppendAttr(const std::vector<std::vector<int64_t>> &attr)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|attr|Input|Attribute value. Currently, only the following types are supported: `bool`, `int64_t`, `float`, `AscendString`, `std::vector<bool>`, `std::vector<int64_t>`, `std::vector<float>`, `std::vector<AscendString>`, `std::vector<std::vector<int64_t>>`.|

## Return Value

Returns a reference of the subclass object type **T** to support chained calls on the subclass.

## Constraints

None
