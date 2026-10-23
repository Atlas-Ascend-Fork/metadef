# Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:36:27.687Z pushedAt=2026-10-15T03:48:04.715Z -->

## Function

**OpLibRegister** constructor and destructor.

## Function Prototype

```cpp
explicit OpLibRegister(const char_t *vendor_name)
OpLibRegister(OpLibRegister &&other) noexcept
OpLibRegister(const OpLibRegister &other)
OpLibRegister &operator=(const OpLibRegister &) = delete
OpLibRegister &operator=(OpLibRegister &&) = delete
~OpLibRegister()
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**vendor_name**|Input|Custom operator vendor name.|
|**other**|Input|Another **OpLibRegister** object.|

## Return Value

Returns an **OpLibRegister** object.

## Constraints

None
