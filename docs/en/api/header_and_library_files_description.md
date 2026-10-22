# Header Files and Library Files

<!-- md-trans-meta sourceCommit=21edba955d3763e74f48b491a55c2a66ccde83c9 translatedAt=2026-10-16T01:36:21.866Z pushedAt=2026-10-16T02:00:17.872Z -->

The basic data structures and structure header files are located in the following directories:

- Graph runtime APIs: ***$\{INSTALL\_DIR\}*/include/exe\_graph/runtime/**
- Graph, GE, and common APIs:
  - ***$\{INSTALL\_DIR\}*/include/graph/**
  - ***$\{INSTALL\_DIR\}*/include/utils/**
  - ***$\{INSTALL\_DIR\}*/include/external/ge\_common/**

- Internal registration APIs and basic support APIs: ***$\{INSTALL\_DIR\}*/pkg\_inc/**
- Context Builder and Runtime definition APIs: ***$\{INSTALL\_DIR\}*/include/base/**
- Operator registration APIs: ***$\{INSTALL\_DIR\}*/include/register/**

The library files are located in the `${INSTALL_DIR}/lib64/` directory. Replace `${INSTALL_DIR}` with the file storage path after CANN software installation. For example, if the **root** user is used for installation, the default file storage path after installation is **/usr/local/Ascend/cann**.

## Graph Runtime APIs

| Header File | Purpose | Corresponding Library File |
| --- | --- | --- |
| exe_graph/runtime/tiling_context.h | Context for tiling function input, output, attributes, and platform information. | Header-only context; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/kernel_run_context.h | C structure definition of the kernel execution context. | Header-only definition; primary consumption library: **libmetadef.so****/libexe_graph.so** |
| exe_graph/runtime/shape.h | Runtime shape dimension description and access. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/compute_node_info.h | Execution node, input/output description, and compile-time node information. | **libmetadef.so**, **libexe_graph.so** (compatibility library) |
| exe_graph/runtime/tensor_data.h | Tensor address, size, placement, and data view. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/op_execute_context.h | Context for operator execution input, output, stream, and workspace. | **libmetadef.so**, **libexe_graph.so** (compatibility library) |
| exe_graph/runtime/op_execute_launch_context.h | Context for the launch phase of two-phase operator execution. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/storage_format.h | Tensor storage format and extended sub-format. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/stride.h | Description of the stride of each tensor dimension. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/tensor.h | Aggregated object of runtime tensor, storage shape, and tensor data. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/continuous_vector.h | Variable-length vector container on contiguous memory. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/exe_res_generation_context.h | Context for generating execution resources, streams, and synchronization resources. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/infer_shape_context.h | Context for operator shape inference. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/range.h | Value range of shape dimensions. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/runtime_attrs.h | Typed read API for runtime attributes. | **libmetadef.so**, **libexe_graph.so** (compatibility library) |
| exe_graph/runtime/base_type.h | Runtime base types, constants, and safe conversion utilities. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/expand_dims_type.h | Storage and query of dimension expansion rules. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/infer_datatype_context.h | Context for inferring the output data type of an operator. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/infer_shape_range_context.h | Context for operator shape range inference. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/context_extend.h | Kernel context extension information and chained extension capability. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/storage_shape.h | Combined description of origin shape and storage shape. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/tiling_parse_context.h | Context for parsing tiling compilation information. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/kernel_context.h | Base class for kernel input/output pointers and context. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/tiling_data.h | **TilingData** buffer writing and capacity management. | **libmetadef.so**, **libexe_graph.so** (compatibility library) |
| exe_graph/runtime/extended_kernel_context.h | Kernel/Tiling execution context supporting extension information. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |
| exe_graph/runtime/op_execute_prepare_context.h | Context for the preparation phase of two-phase operator execution. | Header-only; primary consumption library: **libmetadef.so**/**libexe_graph.so** |

## Graph, GE, and Common APIs

| Header File | Purpose | Corresponding Library File |
| --- | --- | --- |
| graph/tensor.h | Common APIs for **Shape**, **TensorDesc**, and **Tensor**. | **libgraph_base.so** (implementation located in GE/Air) |
| graph/c_types.h | Cross-platform C basic type definitions. | Header-only definition header |
| graph/ge_error_codes.h | Graph status codes, visibility, and deprecated API macros. | Header-only definition header |
| graph/infer_format_context.h | Operator format inference context. | Header-only; primary consumption library **libmetadef.so** |
| graph/compiler_def.h | Compiler common macros and data type definitions. | Header-only definition header |
| graph/ascend_string.h | AscendString string API. | libmetadef.so |
| graph/types.h | Common type APIs such as **Format**, **DataType**, and **TensorType**. | libmetadef.so |
| graph/utils/type_utils.h | **Format**/**DataType** string conversion and validity check. | libmetadef.so |
| graph/kernel_launch_info.h | Creation, serialization, and read/write of device task launch information. | **libregister.so** (implementation located in GE/Air) |
| utils/extern_math_util.h | Integer addition, subtraction, multiplication, and division overflow check utilities. | Header-only utility header |
| ge/ge_allocator.h | GE memory block and allocator abstract API. | Header-only abstract API; primary consumption library **libgert.so** (implementation located in GE/Air) |
| external/ge_common/ge_api_types.h | GE common enums, status, and model data structures. | Header-only definition header |
| external/ge_common/ge_api_error_codes.h | GE error code definition, registration, and text query. | Header-only/inline implementation |
| external/ge_common/ge_error_codes.h | GE error code base types and symbol visibility macros. | Header-only definition header |

## Internal Registration APIs and Basic Support APIs

| Header File | Purpose | Corresponding Library File |
| --- | --- | --- |
| pkg_inc/base/registry/op_impl_space_registry_v2.h | Creation, merging, and querying of operator implementation spaces. | libopp_registry.so |
| pkg_inc/base/registry/opp_package_utils.h | Querying of OPP package paths, versions, and SO descriptions. | libopp_registry.so |
| pkg_inc/base/type/ascend_string_impl.h | **AscendString PImpl** implementation API. | libmetadef.so |
| pkg_inc/base/asc/opcheck/op_check_register_impl.h | Registration implementation of operator check functions. | libopp_registry.so |
| pkg_inc/base/asc/opdef/op_config_registry_impl.h | Registration implementation of operator configurations. | libopp_registry.so |
| pkg_inc/base/asc/opdef/op_def_factory_impl.h | Factory implementation of operator definitions. | libopp_registry.so |
| pkg_inc/base/asc/opdef/op_def_impl.h | Internal implementation of operator, parameter, and attribute definitions. | libopp_registry.so |
| pkg_inc/base/utils/type_utils_impl.h | Conversion utility implementation for **Format**/**DataType**. | libmetadef.so |
| pkg_inc/common/checker.h | Parameter validation and error-return macros. | Header-only utility header |
| pkg_inc/common/ge_common/error_codes_define.h | Encoding and parsing definitions of internal error codes. | Header-only definition header |
| pkg_inc/common/ge_common/scope_guard.h | Scope-exit callback utility. | Header-only/inline implementation |
| pkg_inc/common/ge_common/debug/ge_log.h | GE logging and check macros. | Header-only/inline wrapper |
| pkg_inc/exe_graph/runtime/gert_mem_allocator.h | Abstract API of the GERT multi-stream memory allocator. | Header-only abstract API; primary consumption library **libgert.so** (implementation located in GE/Air) |
| pkg_inc/exe_graph/runtime/gert_mem_block.h | Abstract API of the GERT reference-counted memory block. | Header-only abstract API; primary consumption library **libgert.so** (implementation located in GE/Air) |
| pkg_inc/exe_graph/runtime/gert_tensor_data.h | **TensorData** with ownership and multi-stream sharing capability. | **libgert.so** (implementation located in GE/Air) |
| pkg_inc/graph/any_value.h | Type-erased attribute value container. | libmetadef.so |
| pkg_inc/graph/def_types.h | Basic types and smart pointer aliases internal to **Graph**. | Header-only definition header |
| pkg_inc/graph/type_utils.h | Type identification and specialization API for **AnyValue**. | libmetadef.so |
| pkg_inc/base/asc/tilingdata_base_impl.h | Internal implementation of **TilingData** definitions, field layout, and factory. | libopp_registry.so |

## Context Builder and Runtime Definition APIs

| Header File | Purpose | Corresponding Library File |
| --- | --- | --- |
| base/context_builder/context_holder.h | Management of Kernel Context memory ownership and lifecycle. | libmetadef.so |
| base/context_builder/op_context_builder_base.h | Common base class for operator Context Builder. | libmetadef.so |
| base/context_builder/op_tiling_parse_context_builder.h | Construction of **TilingParseContext**. | libmetadef.so |
| base/context_builder/op_tiling_context_builder.h | Construction of **TilingContext**. | libmetadef.so |
| base/context_builder/op_infer_datatype_context_builder.h | Construction of **InferDataTypeContext**. | libmetadef.so |
| base/context_builder/op_infer_shape_context_builder.h | Construction of **InferShapeContext**. | libmetadef.so |
| base/context_builder/op_infer_shape_range_context_builder.h | Construction of **InferShapeRangeContext**. | libmetadef.so |
| base/context_builder/op_kernel_run_context_builder.h | Construction of KernelContext. | libmetadef.so |
| base/runtime/runtime_attrs_def.h | C memory layout definition of **RuntimeAttrs**. | Header-only definition header; primary consumption libraries **libmetadef.so**/**libexe_graph.so** |

## Operator Registration APIs

| Header File | Purpose | Corresponding Library File |
| --- | --- | --- |
| register/op_impl_registry.h | Registration of host-side operator tiling, inference, and execution functions. | **libopp_registry.so** (also compiled into **librt2_registry.a**) |
| register/op_impl_kernel_registry.h | Operator implementation function table and query API. | **libopp_registry.so** (also compiled into **librt2_registry.a**) |
| register/register_types.h | Common structures and function types for operator registration. | Header-only definition header |
| register/register_fmk_types.h | Framework types and parsed registration types. | Header-only definition header |
| register/register_error_codes.h | Status codes of the registration module. | Header-only definition header |
| register/op_bin_info.h | Generation and verification of operator binary information. | No corresponding SO; **librt2_registry.a** |
| register/tilingdata_base.h | **TilingData** field definition, serialization, and class factory. | **libopp_registry.so** (also compiled into **libtilingdata_base.a** on the device side) |
| register/device_op_impl_registry.h | Registration of device-side operator tiling functions. | No corresponding SO; **libdevice_register.a** |
| register/register.h | Registration of custom operator parsing, framework, and mapping functions. | **libregister.so** (implementation located in GE/Air) |
| register/op_lib_register.h | Registration of the initialization function for the custom operator dynamic library. | **libregister.so** (implementation located in GE/Air) |
| register/asc/op_config_registry.h | Registration of operator AI Core configurations. | libopp_registry.so |
| register/asc/op_def_factory.h | Operator definition creation, query, and Tiling Sink registration. | libopp_registry.so |
| register/asc/op_def.h | Definition of operator inputs, outputs, attributes, and execution capabilities. | libopp_registry.so |
| register/asc/op_def_registry.h | Operator definition registration macros. | Header-only registration entry; calls **libopp_registry.so** |
