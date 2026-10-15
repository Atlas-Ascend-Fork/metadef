# Compat

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:24:44.032Z pushedAt=2026-10-15T03:48:04.697Z -->

## Function

Checks whether the value of the input parameter exceeds the value range that can be represented by the specified data type **T**.

## Function Prototype

**template<typename T1\>**

**static bool Compat\(const T1 v\)**

## Parameters

**Table 1** Template parameters

|Parameter|Description|
|--|--|
|T1|Indicates the type of the value to be checked. Signed integers and unsigned integers are supported, for example, **int64_t** and **uint32_t**.|

**Table 2** Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|v|Input|Value to be checked, of type **T1**.|

## Return Value

Returns a bool value:

- If the value **v** is within the representable range of data type **T**, **true** is returned.
- If the value **v** exceeds the representable range of data type **T**, **false** is returned.

## Constraints

None

## Example

```cpp
const int64_t value = XXX;
if (!ge::IntegerChecker<int32_t>::Compat(value)) {
   // Report an error.
}
```
