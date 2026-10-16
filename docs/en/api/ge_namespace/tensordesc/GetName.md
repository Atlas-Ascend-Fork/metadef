# GetName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:03:39.348Z pushedAt=2026-10-15T03:48:04.761Z -->

## Function

Obtains the name of the tensor described by **TensorDesc**.

## Function Prototype

> [!NOTE] Note
> APIs with the string data type will be deprecated in later versions. You are advised to use APIs with a non-string data type.

```cpp
std::string GetName() const
graphStatus GetName(AscendString &name)
graphStatus GetName(AscendString &name) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|name|Output|Operator name.|

## Return Value

**graphStatus** type: Returns **GRAPH_SUCCESS** if the name is obtained successfully; otherwise, returns **GRAPH_FAILED**.

## Exception Handling

None

## Constraints

None
