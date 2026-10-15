# GetSizeByDataType

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:15:29.652Z pushedAt=2026-10-15T03:48:04.679Z -->

## Function

Obtains the memory size occupied by the passed **data\_type**. To obtain the memory size of multiple elements, use [GetSizeInBytes](GetSizeInBytes.md).

## Function Prototype

```cpp
inline int GetSizeByDataType(DataType data_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|data_type|Input|Data type. See **DataType**.|

## Return Value

Memory size occupied by the **data\_type** (in bytes).

If the memory occupied by the **data\_type** is less than 1 byte, the API returns 1000 plus the number of bits of the data type. For example, for the **DT\_INT4** data type, returns **1004**.

If an invalid value or an unsupported data type is passed, the API returns **-1**.

## Exception Handling

None

## Constraints

None
