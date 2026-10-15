# SetData

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:17:33.123Z pushedAt=2026-10-15T03:48:05.035Z -->

## Function

Sets the data of a tensor.

## Function Prototype

```cpp
void SetData(TensorData &&data)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data|Input|Data to be set. For the definition of the **TensorData** type, see **TensorData**.|

## Return Value

None

## Constraints

None

## Example

```cpp
Tensor t{{{8, 3, 224, 224}, {16, 3, 224, 224}},       // shape
              {ge::FORMAT_ND, ge::FORMAT_FRACTAL_NZ, {}},  // format
              kOnHost,                                // placement
              ge::DT_FLOAT16,                              //dt
              nullptr};
void *a = &t;
TensorData td(a, nullptr);
t.SetData(std::move(td));
```
