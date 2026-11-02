/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software; you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <gtest/gtest.h>
#include <cstdint>
#include <new>
#include <vector>
#include "exe_graph/runtime/continuous_vector.h"

namespace gert {
class ContinuousVectorUT : public testing::Test {};

TEST_F(ContinuousVectorUT, ContinuousVectorVectorInitResetsSize) {
  constexpr size_t kCapacity = 1U;
  const size_t total_size =
      ContinuousVectorVector::GetOverHeadLength(kCapacity) + sizeof(ContinuousVector) + sizeof(int32_t);
  std::vector<uint8_t> storage(total_size);
  auto *vectors = new (storage.data()) ContinuousVectorVector();

  vectors->Init(kCapacity);
  ASSERT_NE(vectors->Add<int32_t>(1U), nullptr);
  ASSERT_EQ(vectors->GetSize(), 1U);

  vectors->Init(kCapacity);
  EXPECT_EQ(vectors->GetSize(), 0U);
  EXPECT_NE(vectors->Add<int32_t>(1U), nullptr);
  EXPECT_EQ(vectors->GetSize(), 1U);
}

TEST_F(ContinuousVectorUT, ContinuousVectorVectorInitZeroCapacityResetsSize) {
  constexpr size_t kCapacity = 1U;
  const size_t total_size =
      ContinuousVectorVector::GetOverHeadLength(kCapacity) + sizeof(ContinuousVector) + sizeof(int32_t);
  std::vector<uint8_t> storage(total_size);
  auto *vectors = new (storage.data()) ContinuousVectorVector();

  vectors->Init(kCapacity);
  ASSERT_NE(vectors->Add<int32_t>(1U), nullptr);
  ASSERT_EQ(vectors->GetSize(), 1U);

  vectors->Init(0U);
  EXPECT_EQ(vectors->GetSize(), 0U);
  vectors->Init(kCapacity);
  EXPECT_NE(vectors->Add<int32_t>(1U), nullptr);
}
}  // namespace gert
