# GetOptionalInputTensor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:08:45.099Z pushedAt=2026-10-15T03:48:04.903Z -->

## Function

Obtains the pointer to the corresponding optional input tensor based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const Tensor *GetOptionalInputTensor(const size_t ir_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**ir_index**|Input|Index of the input in the operator IR prototype definition, counted from 0.|

## Return Value

Input tensor pointer. If **index** is invalid or the input is not instantiated, a null pointer is returned.

For the definition of the **Tensor** type, see [Tensor](../tensor/Tensor.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto data = context->GetOptionalInputTensor(1U)->GetData<uint8_t>();
  EXPECT_EQ(data[0], 85);
  // ...
}
```
