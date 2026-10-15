# GetInputShape

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:38:12.551Z pushedAt=2026-10-15T03:48:05.080Z -->

## Function

Obtains the pointer to the input shape based on the operator input index. The input index here refers to the actual index after operator instantiation, not the index in the prototype definition.

## Function Prototype

```cpp
const StorageShape *GetInputShape(const size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|index|Input|Operator input index, counted from 0.|

## Return Value

Pointer to the specified input shape, which contains both the original shape and the runtime shape information. For the definition of the **StorageShape** type, see [StorageShape](../storageshape/StorageShape.md).

If the input index is invalid, a null pointer is returned.

## Constraints

None

## Example

- Example

  ```cpp
  ge::graphStatus TilingForMul(TilingContext *context) {
    auto input_shape_0 = *context->GetInputShape(0);
    auto input_shape_1 = *context->GetInputShape(1);
    auto output_shape = context->GetOutputShape(0);
    ...
  }
  ```

- Example of obtaining the actual index after operator instantiation

  ```cpp
  ge::graphStatus TilingForXXX(TilingContext *context) {
    // Developers can obtain the instantiation information corresponding to ir_index through the ExtendedKernelContext::GetIrInputInstanceInfo API.
    // This API returns the AnchorInstanceInfo structure. The first instantiated index and the number of instantiations of this input can be obtained through the GetInstanceNum and GetInstanceStart APIs.
    auto ctx = reinterpret_cast<const ExtendedKernelContext *>(context);
    auto instance_info = ctx->GetIrInputInstanceInfo(0); // 0 is the ir index.
    auto instance_num = instance_info->GetInstanceNum(); // Obtain the number of instances of this input.
    auto instance_start = instance_info->GetInstanceStart(); // Obtain the first instantiated index of this input.
    ...
    // In addition, TilingContext also provides an API for obtaining the input based on ir_index.
    auto shape = context->GetOptionalInputShape(0); // Obtain the corresponding optional input shape pointer based on the input index in the operator prototype definition.
    auto shape = context->GetDynamicInputShape(0, 1); // Obtain the corresponding dynamic input shape pointer based on the input index in the operator prototype definition.
    auto shape = context->GetRequiredInputShape(0); // Obtain the corresponding required input shape pointer based on the input index in the operator prototype definition.
  }
  ```
