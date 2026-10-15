# GenSimplifiedKey

<!-- md-trans-meta sourceCommit=bd2bb7f13ebae2d6c71d0a336694b67111dbcd47 translatedAt=2026-10-09T03:26:50.111Z pushedAt=2026-10-15T03:48:04.933Z -->

## Function

Registers the **GenSimplifiedKey** function of an operator to provide a faster binary matching key value.

You need to write a function of the **GenSimplifiedKey** type for the operator and register it through this API.

The **GenSimplifiedKey** type is defined as follows:

```cpp
using GenSimplifiedKeyKernelFunc = UINT32 (*)(TilingContext *, ge::char_t *);
```

The **GenSimplifiedKey** function accepts a **TilingContext** parameter and a **ge::char\_t** parameter as input, through which the operator can customize the simplified key generation logic.

## Function Prototype

```cpp
OpImplRegisterV2 &GenSimplifiedKey(GenSimplifiedKeyKernelFunc gen_simplifiedkey_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|gen_simplifiedkey_func|Input|Custom **GenSimplifiedKey** function to be registered, which is of the **GenSimplifiedKeyKernelFunc** type. The **GenSimplifiedKeyKernelFunc** type is defined as follows:<br>`using GenSimplifiedKeyKernelFunc = UINT32 (*)(TilingContext *, ge::char_t *);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which additionally registers the function for generating the simplified binary matching key.

## Constraints

None

## Registering Through OpDef

When using `OpDef` to define an AscendC operator, you can register a callback through `OpAICoreDef::SetGenSimplifiedKey`. `OP_ADD` forwards this callback to `OpImplRegisterV2` when generating the Tiling registration library.

```cpp
class AddCustom : public OpDef {
 public:
  explicit AddCustom(const char *name) : OpDef(name) {
    this->AICore()
        .SetTiling(TilingFunc)
        .SetGenSimplifiedKey(GenSimplifiedKeyFunc)
        .AddConfig("ascend910b");
  }
};
OP_ADD(AddCustom);
```

This API only registers the user-defined key fragment generation function. The operator type, deterministic mode, and implementation mode in the complete Simplified Key are still assembled by the runtime framework.
