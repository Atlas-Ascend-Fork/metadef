# GetAttrPointer

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:54:05.625Z pushedAt=2026-10-15T03:48:04.984Z -->

## Function

Obtains the operator attribute at the specified index and returns a pointer to this attribute.

## Function Prototype

```cpp
template<typename T>  const T *GetAttrPointer(size_t index) const
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|T|Specified output type|Attribute type.|
|index|Input|Index of the attribute in the IR prototype definition.|

## Return Value

Pointer to the attribute.

## Constraints

None

## Example

```cpp
const RuntimeAttrs * runtime_attrs = kernel_context->GetAttrs();
const gert::ContinuousVector attr0 = runtime_attrs->GetAttrPointer<gert::ContinuousVector>(0);
```
