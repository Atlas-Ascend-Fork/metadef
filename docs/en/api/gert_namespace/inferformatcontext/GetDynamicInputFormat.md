# GetDynamicInputFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:04:42.733Z pushedAt=2026-10-15T03:48:04.897Z -->

## Function

Obtains the corresponding dynamic input format pointer based on the input index in the operator prototype definition.

## Function Prototype

```cpp
StorageFormat *GetDynamicInputFormat(const size_t ir_index, const size_t relative_index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index in the IR prototype definition.|
|relative_index|Input|Relative index after the input is instantiated. For example, if a dynamic input is instantiated into three inputs, the valid range of **relative_index** is [0, 2].|

## Return Value

Pointer of the input format. If **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto format = context->GetDynamicInputFormat(1U, 0U);
  GE_ASSERT_NOTNULL(format);
  // ...
}
```
