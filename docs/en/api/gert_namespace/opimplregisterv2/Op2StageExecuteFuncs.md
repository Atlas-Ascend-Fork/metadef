# Op2StageExecuteFuncs

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:31:09.633Z pushedAt=2026-10-15T03:48:04.939Z -->

## Function

In scenarios where a single operator contains multi-kernel combined execution logic, the operator can use this API to set operator-level callback functions, including a launch preparation callback function and a launch callback function. The launch preparation callback function prepares the parameters used for kernel launch, and the launch callback function implements the launch of multiple kernels. This API is an internal associated API; developers will not call it directly and do not need to pay attention to it for now.

## Function Prototype

```cpp
OpImplRegisterV2 &Op2StageExecuteFuncs(OpExecPrepareFunc prepare_func, OpExecLaunchFunc launch_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|prepare_func|Input|Registered custom **OpExecPrepareFunc** function, which is of type **OpExecPrepareFunc**. The **OpExecPrepareFunc** type is defined as follows:<br>`using OpExecPrepareFunc = UINT32 (*)(OpExecutePrepareContext *);`|
|launch_func|Input|Registered custom **OpExecLaunchFunc** function, which is of type **OpExecLaunchFunc**. The **OpExecLaunchFunc** type is defined as follows:<br>`using OpExecLaunchFunc = UINT32 (*)(OpExecuteLaunchContext *);`|

## Return Value

Returns the **OpImplRegisterV2** object of the operator, which newly registers the operator-level callback function.

## Constraints

None
