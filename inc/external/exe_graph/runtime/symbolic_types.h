/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef METADEF_CXX_INC_EXTERNAL_EXE_GRAPH_RUNTIME_SYMBOLIC_TYPES_H_
#define METADEF_CXX_INC_EXTERNAL_EXE_GRAPH_RUNTIME_SYMBOLIC_TYPES_H_

#include <array>
#include <cstring>
#include <initializer_list>
#include <iostream>
#include <limits>
#include <memory>
#include <type_traits>
#include <vector>
#include "utils/extern_math_util.h"
#include "graph/symbolizer/symbolic.h"

namespace gert {
/*
 * 注意：此类是一个符号化的shape，它的成员变量是一个Expression数组，只在编译态使用，暂不考虑POD形式组织该类
 * */
class SymbolShape {
 public:
  /**
   * 默认构造一个符号化symbol shape，默认构造的shape实例中，dims长度为空
   */
  SymbolShape() = default;

  /**
   * 通过dims值构造符号化shape，例如：SymbolShape({&s0, &s1, &s2, &s3})创建一个Shape实例，有4个维度，
   * 每个维度的值分别是s0, s1, s2, s3
   * @param dims shape的所有dim值
   */
  SymbolShape(const std::initializer_list<ge::Expression> &args) : dims_(args) {}

  /**
   * 拷贝构造函数,移动构造函数
   * @param other
   */
  SymbolShape(const SymbolShape &other) = default;
  SymbolShape &operator=(const SymbolShape &other) = default;
  SymbolShape(SymbolShape &&other) = default;
  SymbolShape &operator=(SymbolShape &&other) = default;

  /**
   * 判断与另外一个shape对象是否相等：dim num相等，且逐维比较时两侧dim均有效的位置symbol值相等；
   * 任一侧dim为非法表达式（如未赋值）时该维视为相等
   * @param rht 另一个Shape对象
   * @return true/false
   */
  bool operator==(const SymbolShape &rht) const {
    if (this->dims_.size() != rht.dims_.size()) {
      return false;
    }
    for (size_t i = 0; i < this->dims_.size(); i++) {
      if ((this->dims_[i].IsValid()) && (rht.dims_[i].IsValid()) && (this->dims_[i] != rht.dims_[i])) {
        return false;
      }
    }
    return true;
  }

  /**
   * 判断与另一个Shape对象是否不等
   * @param rht 另一个SymbolShape对象
   * @return true/false
   */
  bool operator!=(const SymbolShape &rht) const {
    return !(*this == rht);
  }

  /**
   * 获取shape size表达式，如果是scalar场景，返回Symbol(1),如果symbol_shape中某个表达式非法，那么返回Symbol(0)
   * @return shape-size，是一个Expression表达式
   */
  const ge::Expression &GetSymbolShapeSize() const {
    if (symsize_cache_is_valid_) {  // 性能优化，避免重复计算
      return symbol_shape_size_;
    }
    symbol_shape_size_ = ge::Symbol(1);
    for (const auto &dim : dims_) {
      if (dim.IsValid()) {
        symbol_shape_size_ = ge::sym::Mul(symbol_shape_size_, dim);
      } else {
        static auto kZero = ge::Symbol(0);
        return kZero;
      }
    }
    symsize_cache_is_valid_ = true;
    return symbol_shape_size_;
  }

  /**
   * 清空symbol shape的所有维度
   * @return none
   */
  void Clear() {
    symsize_cache_is_valid_ = false;
    dims_.clear();
  }

  /**
   * 获取dim num
   * @return
   */
  size_t GetDimNum() const {
    return dims_.size();
  }

  /**
   * 向后扩展一个dim值，如果扩展的dim数量超出Shape的最大限制，那么本函数不做任何事情
   * @param 扩展的dim值
   * @return this引用
   */
  SymbolShape &AppendDim(const ge::Expression &dim_value) {
    symsize_cache_is_valid_ = false;
    dims_.emplace_back(dim_value);
    return *this;
  }

  /**
   * 设置dim num，若设置的dim num大于当前值，扩展出的维度为非法表达式，需配合SetDim逐维赋值
   * @param dim_num dim的个数
   * @return this引用
   */
  SymbolShape &SetDimNum(size_t dim_num) {
    symsize_cache_is_valid_ = false;
    dims_.resize(dim_num);
    return *this;
  }

  /**
   * 设置第idx位置的dim值
   * @param idx dim的index，调用者需要保证index合法
   * @param dim_value dim值
   * @return this引用
   */
  SymbolShape &SetDim(size_t idx, const ge::Expression &dim_value) {
    symsize_cache_is_valid_ = false;
    dims_[idx] = dim_value;
    return *this;
  }

  /**
   * 获取只读的第idx位置的dim值
   * @param idx dim的index，调用者需要保证index合法
   * @return dim值，Expression指针类型，在idx超出MaxDimNum时，会触发vector访问异常
   */
  const ge::Expression &GetDim(size_t idx) const {
    return dims_[idx];
  }

 private:
  std::vector<ge::Expression> dims_;
  mutable bool symsize_cache_is_valid_{false};  // 性能优化，避免重复计算Symbol shape size
  mutable ge::Expression symbol_shape_size_;
};

class SymbolTensor {
 public:
  SymbolTensor() = default;
  SymbolTensor(const std::initializer_list<ge::Expression> &origin_symbol_shape)
      : origin_symbol_shape_(origin_symbol_shape) {}

  SymbolTensor(const std::initializer_list<ge::Expression> &origin_symbol_shape,
               const std::initializer_list<ge::Expression> &symbolic_values)
      : origin_symbol_shape_(origin_symbol_shape),
        symbolic_values_(std::unique_ptr<std::vector<ge::Expression>>(
            new (std::nothrow) std::vector<ge::Expression>(symbolic_values))) {}

  // 拷贝构造函数
  SymbolTensor(const SymbolTensor &other)
      : origin_symbol_shape_(other.origin_symbol_shape_),
        symbolic_values_(other.symbolic_values_
                             ? std::unique_ptr<std::vector<ge::Expression>>(
                                   new (std::nothrow) std::vector<ge::Expression>(*other.symbolic_values_))
                             : nullptr) {}

  // 拷贝赋值运算符
  SymbolTensor &operator=(const SymbolTensor &other) {
    if (this != &other) {
      origin_symbol_shape_ = other.origin_symbol_shape_;
      if (other.symbolic_values_) {
        symbolic_values_ = std::unique_ptr<std::vector<ge::Expression>>(
            new (std::nothrow) std::vector<ge::Expression>(*other.symbolic_values_));
      } else {
        symbolic_values_.reset();
      }
    }
    return *this;
  }

  // 移动构造函数
  SymbolTensor(SymbolTensor &&other) noexcept = default;

  // 移动赋值运算符
  SymbolTensor &operator=(SymbolTensor &&other) noexcept = default;

  /**
   * 获取只读的原始格式符号化shape
   * @return 原始格式符号化shape引用
   */
  const SymbolShape &GetOriginSymbolShape() const {
    return origin_symbol_shape_;
  }
  /**
   * 设置原始格式符号化shape
   * @return void
   */
  void SetOriginSymbolShape(const SymbolShape &ori_symbol_shape) {
    origin_symbol_shape_ = ori_symbol_shape;
  }

  /**
   * 判断是否存在符号值：无符号值（未设置）返回false；已设置符号值（含个数为0的显式空值）返回true
   * @return 是否存在符号值
   */
  bool HasValue() const {
    return symbolic_values_ != nullptr;
  }
  /**
   * 获取符号值个数，无符号值时返回0
   * @return 符号值个数
   */
  size_t GetValueCount() const {
    return (symbolic_values_ == nullptr) ? 0U : symbolic_values_->size();
  }
  /**
   * 获取只读的第idx位置的符号值
   * @param idx 符号值的index
   * @return 符号值；无符号值或index越界时返回非法表达式（IsValid为false，可检测）
   */
  const ge::Expression &GetValue(size_t idx) const {
    if (symbolic_values_ == nullptr || idx >= symbolic_values_->size()) {
      static const ge::Expression kInvalidExpr;
      return kInvalidExpr;
    }
    return (*symbolic_values_)[idx];
  }
  /**
   * 设置符号值个数，若设置的个数大于当前值，扩展出的符号值为非法表达式，需配合SetValue逐个赋值
   * @param value_count 符号值个数
   * @return this引用
   */
  SymbolTensor &SetValueCount(size_t value_count) {
    if (symbolic_values_ == nullptr) {
      symbolic_values_ = std::unique_ptr<std::vector<ge::Expression>>(new (std::nothrow) std::vector<ge::Expression>());
    }
    if (symbolic_values_ != nullptr) {
      symbolic_values_->resize(value_count);
    }
    return *this;
  }
  /**
   * 设置第idx位置的符号值
   * @param idx 符号值的index，调用者需要保证index合法
   * @param value 符号值
   * @return this引用
   */
  SymbolTensor &SetValue(size_t idx, const ge::Expression &value) {
    if (symbolic_values_ != nullptr) {
      (*symbolic_values_)[idx] = value;
    }
    return *this;
  }

 private:
  SymbolShape origin_symbol_shape_;
  std::unique_ptr<std::vector<ge::Expression>> symbolic_values_;
};
}  // namespace gert
#endif  // METADEF_CXX_INC_EXTERNAL_EXE_GRAPH_RUNTIME_SYMBOLIC_TYPES_H_
