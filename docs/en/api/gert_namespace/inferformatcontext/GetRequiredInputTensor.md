# GetRequiredInputTensor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:10:36.973Z pushedAt=2026-10-15T03:48:04.906Z -->

## Function

Obtains the pointer to the required input tensor based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Tensor *GetRequiredInputTensor(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Input index in the operator IR prototype definition, counted from 0.|

## Return Value

Input tensor pointer. If **ir\_index** is invalid, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto data = context->GetRequiredInputTensor(1U)->GetData<uint8_t>();
  EXPECT_EQ(data[0], 85);
  // ...
}
```
