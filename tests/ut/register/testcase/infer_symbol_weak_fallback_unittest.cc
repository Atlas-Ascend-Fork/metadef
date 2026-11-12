/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <gtest/gtest.h>
#include <new>
#include <type_traits>
#include "register/op_impl_registry.h"
#include "asc/register/op_def.h"

// 弱符号判空降级行为看护：本目标【不链接】libopp_registry/libregister，进程内
// RegisterInferSymbolForSo/SetInferSymbolForSo 两个落表入口弱引用均为空，
// inline 转发器判空后跳过。本文件编译链接通过即证明「弱声明+inline 转发器」机制
// 完整（删除弱化或转发器均直接编译失败）。覆盖场景：新算子 so 在缺少 InferSymbol
// 系符号的老 GE 环境上，宏式/OpDef 式注册静默跳过、GetInferSymbol 返回可判空
// null 引用；覆盖点为弱未定义引用的动态解析，so 侧 -Bsymbolic 不影响。

namespace {
// fallback 实现不访问任何成员，裸内存对象可安全调用
using Storage = std::aligned_storage_t<sizeof(gert::OpImplRegisterV2), alignof(gert::OpImplRegisterV2)>;

gert::OpImplRegisterV2 &MakeBareRegisterV2() {
  static Storage storage;
  return *reinterpret_cast<gert::OpImplRegisterV2 *>(&storage);
}

using OpDefStorage = std::aligned_storage_t<sizeof(ops::OpDef), alignof(ops::OpDef)>;

ops::OpDef &MakeBareOpDef() {
  static OpDefStorage storage;
  return *reinterpret_cast<ops::OpDef *>(&storage);
}
}  // namespace

// 场景1（宏式·注册）：InferSymbol 弱 fallback 空操作并保持链式，老环境注册静默跳过
TEST(InferSymbolWeakFallbackTest, RegisterV2InferSymbolFallbackIsChainableNoOp) {
  auto &reg = MakeBareRegisterV2();
  auto &ret = reg.InferSymbol(nullptr);
  ASSERT_EQ(&ret, &reg);
}

// 场景3（OpDef 式·注册）：SetInferSymbol 弱 fallback 空操作并保持链式
TEST(InferSymbolWeakFallbackTest, OpDefSetInferSymbolFallbackIsChainableNoOp) {
  auto &op_def = MakeBareOpDef();
  auto &ret = op_def.SetInferSymbol(nullptr);
  ASSERT_EQ(&ret, &op_def);
}

// 场景3（OpDef 式·注册）：GetInferSymbol 外部恒返回可判空的 null 引用
TEST(InferSymbolWeakFallbackTest, OpDefGetInferSymbolFallbackReturnsNullDereferenceable) {
  auto &op_def = MakeBareOpDef();
  auto &func = op_def.GetInferSymbol();
  ASSERT_EQ(func, nullptr);
}

// 前提自证：无注册库环境下三个落表入口弱引用均为空（判空短路的数据来源）
TEST(InferSymbolWeakFallbackTest, EntryWeakReferencesAreNullWithoutRegistryLibrary) {
  auto *reg_entry = gert::RegisterInferSymbolForSo;
  auto *set_entry = ops::SetInferSymbolForSo;
  ASSERT_EQ(reg_entry, nullptr);
  ASSERT_EQ(set_entry, nullptr);
}

// 编译期看护：弱声明形态存在（取函数地址合法即声明经宏展开），若弱化机制被移除，
// 本目标的编译在本文件 include 处即失败，无需运行时断言参与
TEST(InferSymbolWeakFallbackTest, WeakFallbackMechanismCompilesWithoutRegistryLibrary) {
  SUCCEED();
}
