# SetData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:56:30.103Z pushedAt=2026-10-15T03:48:04.750Z -->

## Function

Sets data in a tensor.

## Function Prototype

> [!NOTE] Note
> The APIs with the string data type will be deprecated in later versions. You are advised to use the APIs with a non-string data type.

```cpp
graphStatus SetData(std::vector<uint8_t> &&data)
graphStatus SetData(const std::vector<uint8_t> &data)
graphStatus SetData(const uint8_t *data, size_t size)
graphStatus SetData(const std::string &data)
graphStatus SetData(const char_t *data)
graphStatus SetData(const std::vector<std::string> &data)
graphStatus SetData(const std::vector<AscendString> &datas)
graphStatus SetData(uint8_t *data, size_t size, const Tensor::DeleteFunc &deleter_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data/datas|Input|Data to be set.|
|size|Input|Length of the data, in bytes.|
|deleter_func|Input|Used to release the data. **using DeleteFunc = std::function<void(uint8_t *)>;**|

## Return Value

**graphStatus** type: Returns **GRAPH\_SUCCESS** on success; otherwise, returns **GRAPH\_FAILED**.

## Exception Handling

None

## Constraints

None
