# SetStrAttrVal

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:50:21.067Z pushedAt=2026-10-15T03:48:04.873Z -->

## Function

Sets a string-type attribute value into the operator.

## Function Prototype

```cpp
bool SetStrAttrVal(const char *attr_name, const char *val) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|attr_name|Input|Attribute name.|
|val|Input|String to be set.|

## Return Value

Returns whether the attribute value is set successfully.

## Constraints

None

## Example

```cpp
bool SetStrAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  std::string val = "";
  bool result = context->SetStrAttrVal(attr_name.c_str(),val.c_str());
  // ...
}
```
