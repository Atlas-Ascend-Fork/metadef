# SetTilingKey

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:55:04.323Z pushedAt=2026-10-15T03:48:05.108Z -->

## Function

Sets **TilingKey**.

Different kernel implementation branches can be identified by **TilingKey**. After **TilingKey** is set on the host side, the corresponding branch can be selected. For example, an operator may have different algorithm logic under different shapes. The kernel side can select different algorithm logic through **TilingKey**, and the tiling algorithm on the host side also differs. The host side and kernel side are associated through the same **TilingKey**.

## Function Prototype

```cpp
ge::graphStatus SetTilingKey(const uint64_t tiling_key)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|tiling_key|Input|Tiling key to be set.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

The value range of **tiling\_key** is within the **uint64\_t** data type range, but it cannot be set to **UINT64\_MAX**.

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetTilingKey(20);
  // ...
}
```
