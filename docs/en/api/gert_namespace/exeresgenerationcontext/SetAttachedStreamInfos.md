# SetAttachedStreamInfos

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:49:47.265Z pushedAt=2026-10-15T03:48:04.871Z -->

## Function

Attaches a set of stream information to the current operator to specify the execution stream on which the operator runs.

## Function Prototype

```cpp
ge::graphStatus SetAttachedStreamInfos(std::vector<StreamInfo> &stream_info_vec) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|stream_info_vec|Input|Execution stream information, which is of the `std::vector<StreamInfo>` type.|

## Return Value

Returns the [graphStatus](../../ge_namespace/ge-graphStatus.md) status code.

## Constraints

None

## Example

```cpp
ge::graphStatus SetAttachedStreamInfos(ExeResGenerationContext* context) {
  std::vector<StreamInfo> stream_info_vec;
  auto status = context->SetAttachedStreamInfos(stream_info_vec);
  ...
}
```
