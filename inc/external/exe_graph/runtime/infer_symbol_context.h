/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef METADEF_CXX_INC_EXTERNAL_EXE_GRAPH_RUNTIME_INFER_SYMBOL_CONTEXT_H_
#define METADEF_CXX_INC_EXTERNAL_EXE_GRAPH_RUNTIME_INFER_SYMBOL_CONTEXT_H_

#include <cstddef>
#include "exe_graph/runtime/extended_kernel_context.h"
#include "exe_graph/runtime/symbolic_types.h"

namespace gert {
/**
 * 符号化推导上下文：框架在符号化推导阶段以拓扑序逐节点构造并传入，算子开发者
 * 通过本上下文读取输入的符号 Shape 与符号 Tensor，并把推导结果写入输出。
 * 输入符号可能缺失（空指针），调用方需判空后自行降级。
 */
class InferSymbolContext : public ExtendedKernelContext {
 public:
  /**
   * 根据输入index，获取输入符号shape指针
   * @param index 输入index
   * @return 输入符号shape指针，index非法时，返回空指针
   */
  const SymbolShape *GetInputSymbolShape(size_t index) const {
    return GetInputPointer<SymbolShape>(index);
  }

  /**
   * 基于算子IR原型定义，获取`OPTIONAL_INPUT`类型的输入符号shape指针
   * @param ir_index IR原型定义中的index
   * @return 符号shape指针，index非法，或该INPUT没有实例化时，返回空指针
   */
  const SymbolShape *GetOptionalInputSymbolShape(size_t ir_index) const {
    return GetDynamicInputPointer<SymbolShape>(ir_index, 0);
  }

  /**
   * 基于算子IR原型定义，获取`DYNAMIC_INPUT`类型的输入符号shape指针
   * @param ir_index IR原型定义中的index
   * @param relative_index 该输入实例化后的相对index，
   * 例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的有效范围是[0,2]
   * @return 符号shape指针，index或relative_index非法时，返回空指针
   */
  const SymbolShape *GetDynamicInputSymbolShape(size_t ir_index, const size_t relative_index) const {
    return GetDynamicInputPointer<SymbolShape>(ir_index, relative_index);
  }

  /**
   * 基于算子IR原型定义，获取`REQUIRED_INPUT`类型的输入符号shape指针
   * @param ir_index IR原型定义中的index
   * @return 符号shape指针，index非法，或该INPUT没有实例化时，返回空指针
   */
  const SymbolShape *GetRequiredInputSymbolShape(size_t ir_index) const {
    return GetDynamicInputPointer<SymbolShape>(ir_index, 0);
  }

  /**
   * 根据输入index，获取输入符号tensor指针；值仅当算子声明'data'数据依赖时非空
   * @param index 输入index
   * @return 输入符号tensor指针，index非法时，返回空指针
   */
  const SymbolTensor *GetInputSymbolTensor(size_t index) const {
    return GetInputPointer<SymbolTensor>(index);
  }

  /**
   * 基于算子IR原型定义，获取`OPTIONAL_INPUT`类型的输入符号tensor指针；值仅当算子声明'data'数据依赖时非空
   * @param ir_index IR原型定义中的index
   * @return 符号tensor指针，index非法，或该INPUT没有实例化时，返回空指针
   */
  const SymbolTensor *GetOptionalInputSymbolTensor(size_t ir_index) const {
    return GetDynamicInputPointer<SymbolTensor>(ir_index, 0);
  }

  /**
   * 基于算子IR原型定义，获取`DYNAMIC_INPUT`类型的输入符号tensor指针；值仅当算子声明'data'数据依赖时非空
   * @param ir_index IR原型定义中的index
   * @param relative_index 该输入实例化后的相对index，
   * 例如某个DYNAMIC_INPUT实例化了3个输入，那么relative_index的有效范围是[0,2]
   * @return 符号tensor指针，index或relative_index非法时，返回空指针
   */
  const SymbolTensor *GetDynamicInputSymbolTensor(size_t ir_index, const size_t relative_index) const {
    return GetDynamicInputPointer<SymbolTensor>(ir_index, relative_index);
  }

  /**
   * 基于算子IR原型定义，获取`REQUIRED_INPUT`类型的输入符号tensor指针；值仅当算子声明'data'数据依赖时非空
   * @param ir_index IR原型定义中的index
   * @return 符号tensor指针，index非法时，返回空指针
   */
  const SymbolTensor *GetRequiredInputSymbolTensor(size_t ir_index) const {
    return GetDynamicInputPointer<SymbolTensor>(ir_index, 0);
  }

  /**
   * 根据输出index，获取输出符号shape指针（框架持有，调用方写入内容）
   * @param index 输出index
   * @return 输出符号shape指针，index非法时，返回空指针
   */
  SymbolShape *GetOutputSymbolShape(size_t index) {
    return GetOutputPointer<SymbolShape>(index);
  }

  /**
   * 根据输出index，获取输出符号tensor指针（框架持有，调用方写入内容）
   * @param index 输出index
   * @return 输出符号tensor指针，index非法时，返回空指针
   */
  SymbolTensor *GetOutputSymbolTensor(size_t index) {
    return GetOutputPointer<SymbolTensor>(index);
  }
};
static_assert(std::is_standard_layout<InferSymbolContext>::value, "The class InferSymbolContext must be a POD");
}  // namespace gert
#endif  // METADEF_CXX_INC_EXTERNAL_EXE_GRAPH_RUNTIME_INFER_SYMBOL_CONTEXT_H_
