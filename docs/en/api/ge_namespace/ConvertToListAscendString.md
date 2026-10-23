# ConvertToListAscendString

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:07:00.038Z pushedAt=2026-10-15T03:48:04.670Z -->

## Function

Defines a template function **ConvertToListAscendString** for converting string lists of different types into a list of the **AscendString** type.

## Function Prototype

```cpp
template<typename T> std::vector<ge::AscendString> ConvertToListAscendString(T strs)
```

The following two extensions are supported:

- `template<> inline std::vector<ge::AscendString> ConvertToListAscendString(std::vector<std::string> strs)`

  For a string list of the `std::vectorstd::string` type, first convert it to the `std::vector<const char *>` type, and then perform the conversion.

- `template<> inline std::vector<ge::AscendString> ConvertToListAscendString(std::vector<ge::AscendString> strs)`

  For a string list of the `std::vector<ge::AscendString>` type, directly return the original list.

## Parameters

| Parameter | Input/Output | Description |
|--|--|--|
| **strs** | Input | String list to be converted. |

## Return Value

Converted list of **AscendString** strings.

## Exception Handling

None

## Constraints

None
