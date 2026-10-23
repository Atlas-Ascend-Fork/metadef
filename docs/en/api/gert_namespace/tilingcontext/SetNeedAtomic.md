# SetNeedAtomic

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:15:10.913Z pushedAt=2026-10-15T07:29:17.898Z -->

## Function

Sets whether the framework needs to perform the atomic clean operation to ensure that the output memory is initialized before the operator kernel is executed.

Atomic clean is the process of initializing the output memory in Global Memory (GM) before the operator is executed, to ensure the correctness of operations such as accumulation, maximum value calculation, and minimum value calculation.

- Accumulation scenario: Before performing an accumulation operation, the relevant values in global memory must be cleared to zero.
- Maximum value calculation: Before performing a maximum value calculation, the relevant values in Global Memory must be initialized to the minimum value of the corresponding data type.
- Minimum value calculation: Before performing a minimum value calculation, the relevant values in Global Memory must be initialized to the maximum value of the corresponding data type.

The operator can either perform the initialization by itself, or set this API to let the framework complete the initialization by automatically inserting zeroing operators. Using the framework for initialization can leverage the framework's optimization capabilities, for example, by centrally allocating zeroing addresses in graph mode, thereby improving the efficiency of resource management and allocation.

<!-- npu="950,A3,910b,910,310p,310b" id1 -->
**SetNeedAtomic and InitValue are used together. The InitValue API configures which outputs to initialize and the specific initialization values.**
For details about the **InitValue** API, see *[Ascend C API](https://gitcode.com/cann/asc-devkit/blob/9.2.0/docs/zh/api/README.md)*.
<!-- end id1 -->

<!-- @ref: metadef/res/docs/api/SetNeedAtomic_res.md#id1 -->

## Function Prototype

```cpp
ge::graphStatus SetNeedAtomic(const bool atomic)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|atomic|Input|**true**: Atomic clean is required. **false**: Atomic clean is not required.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

**SetNeedAtomic** must be used together with the **InitValue** API; otherwise, the initialization does not take effect.

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetNeedAtomic(true);
  // ...
}
```
