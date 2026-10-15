# SetIntAttrVal

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:49:49.570Z pushedAt=2026-10-15T03:48:04.871Z -->

## Function

Sets an integer-type attribute value to the operator.

## Function Prototype

```cpp
bool SetIntAttrVal(const char *attr_name, const int64_t val) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|attr_name|Input|Attribute name.|
|val|Input|Integer value to be set.|

## Return Value

Returns whether the attribute value is set successfully.

## Constraints

None

## Example

```cpp
bool SetIntAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  int64_t val = 6;
  auto result = context->SetIntAttrVal(attr_name.c_str(),val);
  // ...
}
```
