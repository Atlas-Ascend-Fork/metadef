# GetOptionalInputFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:07:55.205Z pushedAt=2026-10-15T03:48:04.902Z -->

## Function

Obtains the corresponding optional input format pointer based on the input index in the operator prototype definition.

## Function Prototype

```cpp
StorageFormat *GetOptionalInputFormat(const size_t ir_index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index in the IR prototype definition, counted from 0.|

## Return Value

Input format pointer. If **ir\_index** is invalid or the input is not instantiated, a null pointer is returned.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  const auto format = context->GetOptionalInputFormat(0);        // Obtain the format of the 0th input.
  GE_ASSERT_NOTNULL(format);
  // ...
}
```
