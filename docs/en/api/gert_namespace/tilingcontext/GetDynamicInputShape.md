# GetDynamicInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:35:47.040Z pushedAt=2026-10-15T03:48:05.077Z -->

## Function

Obtains the pointer to the shape of the corresponding dynamic input based on the input index in the operator prototype definition.

## Function Prototype

```cpp
const StorageShape *GetDynamicInputShape(const size_t ir_index, const size_t relative_index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|ir_index|Input|Index of the dynamic input in the operator IR prototype definition, starting from 0.|
|relative_index|Input|Relative index of the instantiated input. For example, if a **DYNAMIC_INPUT** is instantiated into three inputs, the value range of **relative_index** is [0, 2].|

## Return Value

Pointer to the specified input shape, which contains both the original shape and the runtime shape. For the definition of the **StorageShape** type, see [StorageShape](../storageshape/StorageShape.md).

If the input **ir\_index** or **relative\_index** is invalid, a null pointer is returned.

## Constraints

None

## Example

```cpp
ge::graphStatus InferShape4ConcatD(TilingContext* context) {
  auto in_shape = context->GetDynamicInputShape(dynamic_input_idx, 0);
  ...
}
```
