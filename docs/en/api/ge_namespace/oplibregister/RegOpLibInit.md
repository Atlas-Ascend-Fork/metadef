# RegOpLibInit

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T01:37:15.257Z pushedAt=2026-10-15T03:48:04.716Z -->

## Function

Registers the initialization function of a custom operator dynamic library.

## Function Prototype

```cpp
OpLibRegister &RegOpLibInit(OpLibInitFunc func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**func**|Input|Custom initialization function to be registered, of type **OpLibInitFunc**. using OpLibInitFunc = uint32_t (*)(ge::AscendString&);|

## Return Value

Returns an **OpLibRegister** object that newly registers the **OpLibInitFunc** function **func**.

## Constraints

None

## Example

```cpp
uint32_t Init(ge::AscendString&) {
  // init func
  return 0;
}

REGISTER_OP_LIB(vendor_1).RegOpLibInit(Init); // Register the initialization function Init for the vendor named vendor_1.
```
