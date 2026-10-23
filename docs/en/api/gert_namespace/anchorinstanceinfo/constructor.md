# Constructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T02:24:04.564Z pushedAt=2026-10-15T03:48:04.788Z -->

## Function

Provides a default constructor and a constructor that specifies two data members.

## Function Prototype

```cpp
AnchorInstanceInfo()
AnchorInstanceInfo(const uint32_t instance_start, const uint32_t instantiation_num)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**instance_start**|Input|Sets the **instance_start_** of this object.|
|**instantiation_num**|Input|Sets the **instantiation_num_** of this object.|

## Return Value

Returns an **AnchorInstanceInfo** object.

## Constraints

None

## Example

```cpp
AnchorInstanceInfo anchor_0(0, 10); //The first input defined by the IR prototype is dynamic, with 10 actual inputs.
```
