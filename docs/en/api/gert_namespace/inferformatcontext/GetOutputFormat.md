# GetOutputFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:08:54.190Z pushedAt=2026-10-15T03:48:04.904Z -->

## Function

Obtains the corresponding output format pointer based on the operator output index. The output index here refers to the actual index after the operator is instantiated, not the index in the prototype definition.

## Function Prototype

```cpp
StorageFormat *GetOutputFormat(const size_t index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator output index, counted from 0.|

## Return Value

Output format pointer. If **index** is invalid, a null pointer is returned.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto format = context->GetOutputFormat(0U);        // Obtain the format of the 0th output.
  // ...
}
```
