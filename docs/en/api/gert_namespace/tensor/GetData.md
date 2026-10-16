# GetData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:11:31.502Z pushedAt=2026-10-15T03:48:05.022Z -->

## Function

Obtains the data address of a tensor.

## Function Prototype

```cpp
template<class T>  const T *GetData() const
template<class T>  auto GetData() -> T*
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|T|Input|Data type.|

## Return Value

Data address.

## Constraints

None

## Example

```cpp
Tensor tensor{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
              kFollowing,                                  // placement
              ge::DT_FLOAT16,                              //dt
              nullptr};
auto addr = tensor.GetData<int64_t>(); // reinterpret_cast<int64_t *>(&tensor + 1)}
```
