# SetListStr

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:50:16.104Z pushedAt=2026-10-15T03:48:04.872Z -->

## Function

Sets a string list attribute value to the operator.

## Function Prototype

```cpp
ge::graphStatus SetListStr(const std::string &attr_name, const std::vector<std::string> &list) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|attr_name|Input|Attribute name.|
|list|Input|String list to be set.|

## Return Value

Returns the [graphStatus](../../ge_namespace/ge-graphStatus.md) status code.

## Constraints

None

## Example

```cpp
ge::graphStatus SetListStr(ExeResGenerationContext* context) {
  std::string attr_name = "";
  std::vector<std::string> list;
  ge::graphStatus status = context->SetListStr(attr_name ,list);
  // ...
}
```
