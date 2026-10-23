# MutableInputTdInfo

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:37:43.295Z pushedAt=2026-10-15T03:48:04.844Z -->

## Function

Obtains the input tensor description of the operator based on the input index. Note that shape information that cannot be determined at compile time is not included in the tensor description (because the shape cannot be determined at compile time, the tensor description does not contain shape information).

## Function Prototype

```cpp
CompileTimeTensorDesc *MutableInputTdInfo(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Index corresponding to the operator input, starting from 0.|

## Return Value

Returns the tensor description. The returned object is non-**const**.

## Constraints

None

## Example

```cpp
  for (size_t i = 0; i < compute_node_info.GetInputsNum(); ++i) {
    auto td = compute_node_info.MutableInputTdInfo(i);
    ...
  }
```
