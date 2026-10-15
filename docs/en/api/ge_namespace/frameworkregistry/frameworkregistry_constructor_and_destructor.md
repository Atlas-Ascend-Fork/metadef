# FrameworkRegistry Constructor and Destructor

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:23:50.268Z pushedAt=2026-10-15T03:48:04.694Z -->

## Function

**FrameworkRegistry** constructor and destructor.

## Function Prototype

```cpp
FrameworkRegistry(const FrameworkRegistry &) = delete
FrameworkRegistry& operator = (const FrameworkRegistry &) = delete
~FrameworkRegistry()
static FrameworkRegistry& Instance()
```

## Parameters

N/A

## Return Value

**Instance\(\)**. Returns the singleton object of **FrameworkRegistry**.

## Exception Handling

None

## Constraints

None
