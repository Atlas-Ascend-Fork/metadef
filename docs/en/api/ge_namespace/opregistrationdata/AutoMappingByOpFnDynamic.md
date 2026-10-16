# AutoMappingByOpFnDynamic

<!-- md-trans-meta sourceCommit=e644a5b0043dce46383ff72574dad115120b2ba7 translatedAt=2026-10-09T01:38:57.650Z pushedAt=2026-10-15T03:48:04.719Z -->

## Function

Automatic mapping callback function for operators with dynamic inputs/outputs.

## Function Prototype

```cpp
Status AutoMappingByOpFnDynamic(const ge::Operator &op_src, ge::Operator &op, const std::vector<DynamicInputOutputInfo> &dynamic_name_attr_value)
```

## Parameters

|Parameter|Input/Output|Description|
|--|--|--|
|op_src|Input|Operator in the original model before conversion, containing the attributes of the operator in the original model.|
|op|Input|Operator adapted to the AI processor.|
|dynamic_name_attr_value|Input|Describes the actual number of dynamic inputs and outputs. For details about the **DynamicInputOutputInfo** data structure, see the "DynamicInputOutputInfo Data Structure".|

For details about the **Operator** class, see *[GE Graph Engine API](https://gitcode.com/cann/ge/blob/master/docs/zh/api/graph_engine_api/README.md)*.

## DynamicInputOutputInfo Data Structure

```cpp
constexpr int64_t kMaxNameLength = 1048576; // 1M
enum DynamicType : int16_t {
  kInvalid = 0,
  kInput = 1,
  kOutput = 2
};
struct DynamicInputOutputInfo {
  DynamicType type; // input/output
  const char_t *port_name;
  int64_t port_name_len;
  const char_t *attr_name;
  int64_t attr_name_len;
  DynamicInputOutputInfo(const DynamicType type_instance, const char_t *const port_name_instance,
                         const int64_t port_name_len_instance, const char_t *const attr_name_instance,
                         const int64_t attr_name_len_instance)
      : type(type_instance), port_name(port_name_instance), port_name_len(port_name_len_instance),
        attr_name(attr_name_instance), attr_name_len(attr_name_len_instance) {}
  DynamicInputOutputInfo() : DynamicInputOutputInfo(kInvalid, nullptr, 0L, nullptr, 0L) {}
};
```

|Parameter|Description|
|--|--|
|**type**|Specifies whether it is a dynamic input or output. **0**: invalid value. **1**: input. **2**: output.|
|**port_name**|Port name, which is the name of the input or output.|
|**port_name_len**|Port name length, with a maximum length of **kMaxNameLength**.|
|**attr_name**|Attribute name.|
|**attr_name_len**|Attribute name length, with a maximum length of **kMaxNameLength**.|

## Example

```cpp
Status QueueDequeueUpToMapping(const  ge::Operator& op_src, ge::Operator& op) {
vector<DynamicInputOutputInfo> dynamic_name_attr_value;
string port_name = "components";
string attr_name = "component_types";
DynamicInputOutputInfo name_attr(kOutput, port_name.c_str(), port_name.size(), attr_name.c_str(), attr_name.size());
dynamic_name_attr_value.push_back(name_attr);
AutoMappingByOpFnDynamic(op_src, op, dynamic_name_attr_value);
return SUCCESS;
}

REGISTER_CUSTOM_OP("QueueDequeueUpTo")
.FrameworkType(TENSORFLOW)
.OriginOpType("QueueDequeueUpToV2")
.ParseParamsByOperatorFn(QueueDequeueUpToMapping)
.ImplyType(ImplyType::AI_CPU);
```
