/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/range.h"
#include <gtest/gtest.h>

namespace gert {
class RangeUT : public testing::Test {};

TEST_F(RangeUT, EmptyRangeEqualsEmptyRange) {
  Range<int> empty1;
  Range<int> empty2;

  EXPECT_TRUE(empty1 == empty2);
}

TEST_F(RangeUT, EmptyRangeNotEqualsBoundedRangeBothOrders) {
  int min = 1;
  int max = 5;
  Range<int> empty;
  Range<int> bounded(&min, &max);

  EXPECT_FALSE(empty == bounded);
  EXPECT_FALSE(bounded == empty);
}

TEST_F(RangeUT, BoundedRangesWithEqualValuesAreEqual) {
  int min1 = 1;
  int max1 = 5;
  int min2 = 1;
  int max2 = 5;
  Range<int> range1(&min1, &max1);
  Range<int> range2(&min2, &max2);

  EXPECT_TRUE(range1 == range2);
}

TEST_F(RangeUT, BoundedRangesWithUnequalValuesAreNotEqual) {
  int min1 = 1;
  int max1 = 5;
  int min2 = 1;
  int max2 = 6;
  Range<int> range1(&min1, &max1);
  Range<int> range2(&min2, &max2);

  EXPECT_FALSE(range1 == range2);
}

TEST_F(RangeUT, OneSidedNullEndpointIsSafeAndNotEqual) {
  int min = 1;
  int max = 5;
  Range<int> partial(&min, nullptr);
  Range<int> bounded(&min, &max);

  EXPECT_FALSE(partial == bounded);
  EXPECT_FALSE(bounded == partial);
}
}  // namespace gert
