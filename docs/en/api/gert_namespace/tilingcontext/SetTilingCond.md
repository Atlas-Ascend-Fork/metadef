# SetTilingCond

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:54:07.986Z pushedAt=2026-10-15T03:48:05.107Z -->

## Function

Sets the tiling condition. The tiling condition is an integer value used to select the tiling implementation actually used by the operator.

## Function Prototype

```cpp
ge::graphStatus SetTilingCond(int32_t tiling_cond)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|tiling_cond|Input|Tiling condition to be set.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

For the definition of **graphStatus**, see [ge::graphStatus](../../ge_namespace/ge-graphStatus.md).

## Constraints

None

## Example

```cpp
ge::graphStatus Tiling4XXX(TilingContext* context) {
  auto ret = context->SetTilingCond(10);
  // ...
}
```
