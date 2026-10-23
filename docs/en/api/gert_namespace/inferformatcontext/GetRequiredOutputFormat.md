# GetRequiredOutputFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:10:58.717Z pushedAt=2026-10-15T03:48:04.906Z -->

## Function

Obtains the required output Format pointer based on the output index in the operator prototype definition.

## Function Prototype

```cpp
StorageFormat *GetRequiredOutputFormat(const size_t ir_index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index in the IR prototype definition, counted from 0.|

## Return Value

Input format pointer. If **ir\_index** is invalid, a null pointer is returned.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto format = context->GetRequiredOutputFormat(0);
   // ...
}
```
