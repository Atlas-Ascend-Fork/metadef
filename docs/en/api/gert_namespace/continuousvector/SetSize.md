# SetSize

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:42:49.964Z pushedAt=2026-10-15T03:48:04.856Z -->

## Function

Sets the number of currently stored elements.

## Function Prototype

```cpp
ge::graphStatus SetSize(const size_t size)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**size**|Input|Number of currently stored elements.|

## Return Value

Returns **ge::GRAPH\_SUCCESS** on success.

Returns **ge::GRAPH\_FAILED** on failure when the set **size** is greater than capacity.

## Constraints

None

## Example

```cpp
size_t capacity = 100U;
auto cv_holder = ContinuousVector::Create<int64_t>(capacity);
auto cv = reinterpret_cast<ContinuousVector *>(cv_holder.get());
auto ret = cv->SetSize(10U); // ge::GRAPH_SUCCESS
ret = cv->GetSize(101U); // ge::GRAPH_FAILED
```
