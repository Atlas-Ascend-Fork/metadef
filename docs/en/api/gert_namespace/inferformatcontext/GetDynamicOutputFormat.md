# GetDynamicOutputFormat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:05:52.237Z pushedAt=2026-10-15T03:48:04.899Z -->

## Function

Obtains the corresponding dynamic output **Format** pointer based on the output index in the operator prototype definition.

## Function Prototype

```cpp
StorageFormat *GetDynamicOutputFormat(const size_t ir_index, const size_t relative_index)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index in the IR prototype definition, counted from 0.|
|relative_index|Input|Relative index after the operator output is instantiated. For example, if a dynamic output is instantiated into three outputs, the valid range of **relative_index** is [0, 2].|

## Return Value

Output **Format** pointer. If **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

For the definition of the **StorageFormat** type, see [StorageFormat](../storageformat/StorageFormat.md).

## Constraints

None

## Example

```cpp
ge::graphStatus InferFormatForXXX(InferFormatContext *context) {
  auto format = context->GetDynamicOutputFormat(0U, 0U);
  // ...
}
```
