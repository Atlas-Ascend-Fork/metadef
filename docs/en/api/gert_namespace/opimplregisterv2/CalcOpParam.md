# CalcOpParam

<!-- md-trans-meta sourceCommit=ea046bd50b7a6b8b6ef9ddbedb3c55664c72b8ae translatedAt=2026-10-09T03:25:12.188Z pushedAt=2026-10-15T03:48:04.929Z -->

## Function

Calculates and allocates resources in the **GenerateTask** phase.

## Function Prototype

```cpp
OpImplRegisterV2 &CalcOpParam(OpCalcParamKernelFunc calc_op_param_func)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|calc_op_param_func|Input|**OpCalcParamKernel** function to be registered. The **OpCalcParamKernelFunc** type is defined as follows: **using OpCalcParamKernelFunc = UINT32 (*)(ExeResGenerationContext* context);**|

## Return Value

Returns the **OpImplRegisterV2** object of the operator itself, which now has the **OpCalcParamKernelFunc** function newly registered.

## Constraints

None
