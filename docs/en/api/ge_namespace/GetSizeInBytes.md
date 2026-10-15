# GetSizeInBytes

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:15:53.943Z pushedAt=2026-10-15T03:48:04.680Z -->

## Function

Obtains the total memory size occupied by **element\_count** of the **data\_type** based on the passed-in **element\_count** and **data\_type**.

## Function Prototype

```cpp
int64_t GetSizeInBytes(int64_t element_count, DataType data_type)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|element_count|Input|Identifies how many **data_type** elements are involved.|
|data_type|Input|Data type. See **DataType**.|

## Return Value

Returns **-1** if the passed-in count is an invalid value or the passed-in data type is unsupported.

## Exception Handling

None

## Constraints

None
