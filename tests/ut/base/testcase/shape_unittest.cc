/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include "exe_graph/runtime/shape.h"
#include "exe_graph/runtime/expand_dims_type.h"
#include <gtest/gtest.h>
#include <string>

namespace gert {
class ShapeUT : public testing::Test {};

TEST_F(ShapeUT, SetDimDoesNotChangeRank) {
  Shape shape;
  shape.SetDim(0, 7);
  EXPECT_EQ(shape.GetDimNum(), 0);
  EXPECT_EQ(shape.GetDim(0), 7);

  shape.SetDim(2, 9);
  EXPECT_EQ(shape.GetDimNum(), 0);
  EXPECT_EQ(shape.GetDim(2), 9);

  shape.SetDimNum(3);
  shape.SetDim(2, 11);
  EXPECT_EQ(shape.GetDimNum(), 3);
  EXPECT_EQ(shape.GetDim(2), 11);
}

TEST_F(ShapeUT, EmptyShapeSizeIsIndependentOfDimensionOrder) {
  const Shape overflow_before_zero{256, 256, 256, 256, 256, 256, 256, 256, 0};
  const Shape zero_before_overflow{0, 256, 256, 256, 256, 256, 256, 256, 256};
  const Shape overflowing_nonempty{256, 256, 256, 256, 256, 256, 256, 256};

  EXPECT_EQ(overflow_before_zero.GetShapeSize(), 0);
  EXPECT_EQ(zero_before_overflow.GetShapeSize(), 0);
  EXPECT_EQ(overflowing_nonempty.GetShapeSize(), Shape::kInvalidDimValue);
}

TEST_F(ShapeUT, SetDimNumRejectsOutOfRange) {
  Shape shape({1, 2, 3});
  shape.SetDimNum(Shape::kMaxDimNum + 1);
  EXPECT_EQ(shape.GetDimNum(), 3);

  shape.SetDimNum(Shape::kMaxDimNum);
  EXPECT_EQ(shape.GetDimNum(), Shape::kMaxDimNum);
  shape.SetDimNum(Shape::kMaxDimNum + 1);
  EXPECT_EQ(shape.GetDimNum(), Shape::kMaxDimNum);
}

TEST_F(ShapeUT, ExpandDimsIntegerKeepsMaskBitsAboveEight) {
  const auto encoded = static_cast<int64_t>((static_cast<uint64_t>(9) << 56U) | (static_cast<uint64_t>(1) << 8U));
  const ExpandDimsType integer_rule(encoded);
  std::string rule_text(9U, '0');
  rule_text.back() = '1';
  const ExpandDimsType string_rule(rule_text.c_str());
  const Shape input({2, 3, 4, 5, 6, 7, 8, 9});
  Shape from_integer;
  Shape from_string;

  EXPECT_EQ(integer_rule, string_rule);
  EXPECT_EQ(integer_rule.Expand(input, from_integer), ge::GRAPH_SUCCESS);
  EXPECT_EQ(string_rule.Expand(input, from_string), ge::GRAPH_SUCCESS);
  ASSERT_EQ(from_integer.GetDimNum(), 9U);
  ASSERT_EQ(from_string.GetDimNum(), 9U);
  for (size_t i = 0; i < 8; ++i) {
    EXPECT_EQ(from_integer.GetDim(i), input.GetDim(i));
    EXPECT_EQ(from_string.GetDim(i), input.GetDim(i));
  }
  EXPECT_EQ(from_integer.GetDim(8), 1);
  EXPECT_EQ(from_string.GetDim(8), 1);
}
}  // namespace gert
