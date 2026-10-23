# SetName

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:09:00.029Z pushedAt=2026-10-15T03:48:04.768Z -->

## Function

Sets the name of a Tensor in **TensorDesc**.

## Function Prototype

> [!NOTE] Note
> The API with the string data type will be deprecated in later versions. You are advised to use the API with a non-string data type.

```cpp
void SetName(const std::string &name)
void SetName(const char_t *name)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|name|Input|Name of the tensor to be set.|

## Return Value

None

## Exception Handling

None

## Constraints

None
