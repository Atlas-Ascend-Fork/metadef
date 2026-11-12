/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <gtest/gtest.h>
#include "graph/any_value.h"
#include "register/op_impl_registry_base.h"
#include "register/op_impl_kernel_registry.h"

namespace gert {
namespace {
constexpr const size_t kMapSize = 48U;
constexpr const size_t kVirtualTableSize = 8U;
constexpr const size_t kReservedFieldSize = 8U;
constexpr const size_t kReservedFieldSize2 = 40U;
constexpr const size_t kOpImplRegistrySize = 88U + kVirtualTableSize;

// 保留区拆分：reserved_[1]（槽0=PCIe 透传，kPcieThroughFlagIdx 历史语义不变）+
// infer_symbol（消费槽1）+ reserved2_[498] 尾部保留（总尺寸不变，仍为 kOpImplSize）
constexpr const size_t kOpImplReservedFieldSize = 498UL * sizeof(void *);
constexpr const size_t kOpImplSize = 4304UL;

}  // namespace

class AbiCompatibilityForRegisterUT : public testing::Test {};
TEST_F(AbiCompatibilityForRegisterUT, OpImplRegistry_CheckMemLayoutNotChanged) {
  OpImplRegistry r;
  ASSERT_EQ(sizeof(r), kOpImplRegistrySize);
  ASSERT_EQ(reinterpret_cast<uintptr_t>(&r.types_to_impl_) - reinterpret_cast<uintptr_t>(&r), kVirtualTableSize);

  EXPECT_EQ(reinterpret_cast<uintptr_t>(&r.reserved_) - reinterpret_cast<uintptr_t>(&r.types_to_impl_), kMapSize);
  EXPECT_EQ(sizeof(r.reserved_), kReservedFieldSize2);
}

TEST_F(AbiCompatibilityForRegisterUT, OpImplFunctionsV2_CheckMemLayoutNotChanged) {
  gert::OpImplKernelRegistry::OpImplFunctionsV2 r;
  ASSERT_EQ(sizeof(r), kOpImplSize);
  // 布局拆分后分字段守护：reserved_[1]（槽0=PCIe 透传）+ infer_symbol（消费槽1）
  // + reserved2_[498]（尾部保留），消费区总量维持原 500 槽不变
  EXPECT_EQ(sizeof(r.reserved_), 1UL * sizeof(void *));
  EXPECT_EQ(sizeof(r.reserved2_), kOpImplReservedFieldSize);
  EXPECT_EQ(sizeof(r.reserved_) + sizeof(r.infer_symbol) + sizeof(r.reserved2_), 500UL * sizeof(void *));
}
}  // namespace gert
