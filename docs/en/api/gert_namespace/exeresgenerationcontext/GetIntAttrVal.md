# GetIntAttrVal

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:46:59.086Z pushedAt=2026-10-15T03:48:04.865Z -->

## Function

Obtains the integer-type attribute value of an operator.

## Function Prototype

```cpp
bool GetIntAttrVal(const char *attr_name, int64_t &val) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|attr_name|Input|Attribute name.|
|val|Output|Receives the obtained integer value.|

## Return Value

Returns whether the attribute is successfully obtained.

## Constraints

None

## Example

```cpp
bool GetIntAttrVal(ExeResGenerationContext* context) {
  std::string attr_name = "";
  int64_t val;
  auto result = context->GetStrAttrVal(attr_name.c_str(),val);
  // ...
}
```
