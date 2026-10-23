# GetInputFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:06:05.507Z pushedAt=2026-10-15T03:48:04.900Z -->

## Function

Obtains the input format pointer based on the operator input index. The input index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
StorageFormat *GetInputFormat(const size_t index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Input **Format** pointer. If **index** is invalid, a null pointer is returned.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto format = context->GetInputFormat(0);        // Obtain the format of 0th input.
  GE_ASSERT_NOTNULL(format);
  // ...
}
```
