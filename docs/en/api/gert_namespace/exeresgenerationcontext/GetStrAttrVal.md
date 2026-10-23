# GetStrAttrVal

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:48:16.572Z pushedAt=2026-10-15T03:48:04.867Z -->

## Function

Obtains the string-type attribute value of an operator.

## Function Prototype

```cpp
bool GetStrAttrVal(const char *attr_name, ge::AscendString &val) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|attr_name|Input|Attribute name.|
|val|Output|Receives the obtained string value.|

## Return Value

Returns whether the attribute is successfully obtained.

## Constraints

None

## Example

```cpp
bool GetStrAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  ge::AscendString val;
  auto result = context->GetStrAttrVal(attr_name.c_str(),val);
  // ...
}
```
