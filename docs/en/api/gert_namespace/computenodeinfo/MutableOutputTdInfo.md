# MutableOutputTdInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:38:23.986Z pushedAt=2026-10-15T03:48:04.845Z -->

## Function

Obtains the output tensor description of the operator. Note that shape information that cannot be determined at compile time is not included in the tensor description (because the shape cannot be determined at compile time, the tensor description does not contain shape information).

## Function Prototype

```cpp
CompileTimeTensorDesc *MutableOutputTdInfo(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index corresponding to the operator output, counting from 0.|

## Return Value

Tensor description. The returned object is non-**const**.

## Constraints

None

## Example

```cpp
for (size_t i = 0; i < node->GetAllOutDataAnchorsSize(); ++i) {
    auto td = compute_node_info.MutableOutputTdInfo(i);
    ...
}
```
