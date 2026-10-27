# Append

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T04:55:49.986Z pushedAt=2026-10-15T03:48:05.109Z -->

## Function

Appends tiling data to the end. If the appended data exceeds the maximum storable length, the append operation fails.

## Function Prototype

```cpp
template<typename T, typename std::enable_if<std::is_standard_layout<T>::value, int>::type = 0>  ge::graphStatus Append(const T &data)

template<typename T, typename std::enable_if<std::is_standard_layout<T>::value, int>::type = 0>  ge::graphStatus Append(const T *data, size_t append_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**T**|Input|Type of the tiling data to append.|
|**data**|Input|Reference type: instance of the tiling data to append. Pointer type: start address of the tiling data to append.|
|**append_num**|Input|Number of tiling data elements to append. A total of **append_num** tiling data elements of type **T** are appended.|

## Return Value

- Returns **ge::GRAPH\_SUCCESS** on success.
- **Append(const T &data)** returns **ge::GRAPH\_FAILED** on failure.
- **Append(const T *data, size_t append_num)** returns **ge::GRAPH\_MUL\_OVERFLOW** if the product of **sizeof(T)** and **append_num** overflows, and **ge::GRAPH\_ADD\_OVERFLOW** if the length addition overflows or the appended length exceeds the capacity.

## Constraints

The appended tiling data must conform to **standard\_layout**, that is, flat memory layout.

## Example

```cpp
auto td_buf = TilingData::CreateCap(100U);
auto td = reinterpret_cast<TilingData *>(td_buf.get());

// 1
struct AppendData{
  int a = 10;
  int b = 100;
};
AppendData ad;
auto ret = td->Append<AppendData>(ad); // ge::GRAPH_SUCCESS

// 2
size_t append_num = 10;
int32_t *td = new int32_t[append_num];
auto ret = td->Append<int32_t>(td, append_num); // ge::GRAPH_SUCCESS

// 3
size_t append_num = 50;
int32_t *td = new int32_t[append_num];
auto ret = td->Append<int32_t>(td, append_num); // ge::GRAPH_ADD_OVERFLOW
```
