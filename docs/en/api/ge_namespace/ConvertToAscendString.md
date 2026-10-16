# ConvertToAscendString

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:05:45.845Z pushedAt=2026-10-15T03:48:04.670Z -->

## Function

A template function that accepts a template parameter **T** and converts it to the **AscendString** type. The main purpose of this function is to convert strings of different types to the **AscendString** type.

## Function Prototype

```cpp
template<typename T> ge::AscendString ConvertToAscendString(T str)
```

The following extensions are supported:

- `template<> inline ge::AscendString ConvertToAscendString<const char *>(const char *str)`

  For a string of the `const char *1` type, the AscendString constructor is used directly for conversion.

- `template<> inline ge::AscendString ConvertToAscendString<std::string>(std::string str)`

  For a string of the **std::string** type, it is first converted to the `const char *` type before conversion.

- `template<> inline ge::AscendString ConvertToAscendString<ge::AscendString>(ge::AscendString str)`

  For a string of the **AscendString** type, the **AscendString** type string is returned directly.

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|str|Input|String to be converted.|

## Return Value

Converted **AscendString** string.

## Exception Handling

None

## Constraints

None
