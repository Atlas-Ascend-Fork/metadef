# operator<<

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:59:24.863Z pushedAt=2026-10-15T03:48:05.117Z -->

## Function

Uses the **<<** operator overload to append tiling data. If the appended data exceeds the maximum storable length, this operation is ignored.

Appending tiling data with **<<** provides the same functionality as [Append](Append.md), and using this operator is more intuitive and convenient.

## Function Prototype

```cpp
template<typename T>

TilingData &operator<<(TilingData &out, const T &data)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|T|Input|Type of the tiling data to be appended.|
|out|Output|Instance of the **TilingData** class.|
|data|Input|Instance of the tiling data to be appended.|

## Return Value

**TilingData** object with data appended.

## Constraints

None

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());

struct AppendData{
  int a = 10;
  int b = 100;
};
AppendData ad;
(*td) << ad;
auto data_size = td.GetDataSize(); // 2 * sizeof(int)
```
