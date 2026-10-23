# AutoMappingByOpFn

<!-- md-trans-meta sourceCommit=78fdc00e49104854a42b651a70a25605cca9a4ad translatedAt=2026-10-15T06:10:17.189Z pushedAt=2026-10-15T07:29:17.886Z -->

## Function

Automatic mapping callback function.

## Function Prototype

```cpp
Status AutoMappingByOpFn(const ge::Operator &op_src, ge::Operator &op);
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|**op_src**|Input|Operator in the original model before conversion, containing the attributes of the operator in the original model.|
|**op**|Input|Operator adapted to the AI processor.|

For details about the **Operator** class, see *[GE Graph Engine API](https://gitcode.com/cann/ge/blob/9.2.0/docs/zh/api/graph_engine_api/README.md)*.

## Example

Scenario where the attributes of the original TensorFlow operator and the operator adapted to the AI processor are mapped one-to-one:

```cpp
REGISTER_CUSTOM_OP("SoftplusGrad")
.FrameworkType(TENSORFLOW)
.OriginOpType("SoftplusGrad")
.ParseParamsByOperatorFn(AutoMappingByOpFn)
.ImplyType(ImplyType::TVM);
```

Scenario where the attributes of the original TensorFlow operator and the operator adapted to the AI processor cannot be mapped one-to-one:

```cpp
Status ParseResizeArea(const ge::Operator &op_src, ge::Operator& op)
  {
    AutoMappingByOpFn(op_src, op);

    ge::TensorDesc input_tensor = op.GetInputDesc("images");
    input_tensor.SetOriginFormat(ge::FORMAT_NHWC);
    input_tensor.SetFormat(ge::FORMAT_NHWC);
    auto ret = op.UpdateInputDesc("images", input_tensor);
    if(ret != ge::GRAPH_SUCCESS){
        return FAILED;
    }
    ge::TensorDesc output_tensor = op.GetOutputDesc("y");
    output_tensor.SetOriginFormat(ge::FORMAT_NHWC);
    output_tensor.SetFormat(ge::FORMAT_NHWC);
    auto ret_output = op.UpdateOutputDesc("y", output_tensor);
    if(ret_output != ge::GRAPH_SUCCESS){
        return FAILED;
    }
    return SUCCESS;
  }
// register ResizeArea op to GE
REGISTER_CUSTOM_OP("ResizeArea")
  .FrameworkType(TENSORFLOW)
  .OriginOpType("ResizeArea")
  .ParseParamsByOperatorFn(ParseResizeArea)
  .ImplyType(ImplyType::AI_CPU);
```
