/**
 * Copyright (c) 2026 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#ifndef GRAPH_SYMBOLIZER_SYMBOLIC_H_
#define GRAPH_SYMBOLIZER_SYMBOLIC_H_

#include <cstdint>
#include <limits>
#include <memory>
#include <ostream>
#include <type_traits>
#include <utility>
#include <vector>
#include "graph/error_codes.h"
#include "graph/types.h"

// 弱符号声明：复用 graph/types.h 的 WEAK_SYMBOL（自带 __GNUC__ 分支与 #ifndef 保护）。
// 外部工程（如自定义算子包）引用本头文件时，对 Expression / Symbol / ge::sym::* 产生
// 弱未定义符号，执行机（无 symbolizer）上置空、不阻断 dlopen；与 metadef 既有的
// RecordTilingStruct、gert_TilingContextBuilder_* 跨包弱符号兼容机制一致

namespace ge {
class Expression;
class ExpressionImpl;
class ShapeEnvAttr;
using ExpressionImplPtr = std::unique_ptr<ExpressionImpl>;

namespace sym {
WEAK_SYMBOL Expression Add(const Expression &a, const Expression &b);
WEAK_SYMBOL Expression Sub(const Expression &a, const Expression &b);
WEAK_SYMBOL Expression Mul(const Expression &a, const Expression &b);
WEAK_SYMBOL Expression Div(const Expression &a, const Expression &b);
WEAK_SYMBOL Expression Max(const Expression &a, const Expression &b);
WEAK_SYMBOL Expression Min(const Expression &a, const Expression &b);
WEAK_SYMBOL Expression Pow(const Expression &base, const Expression &exp);
WEAK_SYMBOL Expression Exp(const Expression &a);
WEAK_SYMBOL Expression Mod(const Expression &base, const Expression &exp);
WEAK_SYMBOL Expression Abs(const Expression &a);
WEAK_SYMBOL Expression Log(const Expression &a);  // 默认以E为底
WEAK_SYMBOL Expression Log(const Expression &arg, const Expression &base);
WEAK_SYMBOL Expression Coeff(const Expression &b, const Expression &x, const Expression &n);
WEAK_SYMBOL Expression Rational(int32_t num, int32_t den);  // 分数
WEAK_SYMBOL Expression Ceiling(const Expression &a);
WEAK_SYMBOL Expression Align(const Expression &arg, uint32_t alignment);
WEAK_SYMBOL Expression AlignWithPositiveInteger(const Expression &arg, uint32_t alignment);
WEAK_SYMBOL Expression Floor(const Expression &arg);
WEAK_SYMBOL Expression Eq(const Expression &a, const Expression &b);  // ==
WEAK_SYMBOL Expression Ne(const Expression &a, const Expression &b);  // !=
WEAK_SYMBOL Expression Ge(const Expression &a, const Expression &b);  // >=
WEAK_SYMBOL Expression Gt(const Expression &a, const Expression &b);  // >
WEAK_SYMBOL Expression Le(const Expression &a, const Expression &b);  // <=
WEAK_SYMBOL Expression Lt(const Expression &a, const Expression &b);  // <
WEAK_SYMBOL Expression Not(const Expression &a);                      // !
WEAK_SYMBOL Expression Neg(const Expression &a);                      // 负号
WEAK_SYMBOL Expression LogicalAnd(const std::vector<Expression> &a);
WEAK_SYMBOL Expression LogicalOr(const std::vector<Expression> &a);
}  // namespace sym

enum class ExprType : uint32_t {
  kExprConstantInteger = 0,
  kExprConstantRealDouble = 1,
  kExprConstantRation = 2,
  kExprConstantBoolean = 3,
  // add const defination here
  kExprVariable = 100,
  // add variable defination here
  kExprOperation = 200,
  kExprOperationBoolean,
  // add operation defination here
  kExprNone = std::numeric_limits<uint32_t>::max()
};

enum class StrType : size_t {
  kStrCpp = 0,
  kStrExpr = 1,  // kStrExpr和kStrCpp只有在处理除法的时候有区别，例如Div(a,b): kStrExpr返回a/b，kStrCpp返回Rational(a,b)
  kStrEnd = 2,
};

class Expression {
 public:
  WEAK_SYMBOL Expression();
  WEAK_SYMBOL ~Expression();
  WEAK_SYMBOL Expression(const Expression &other);
  WEAK_SYMBOL Expression(Expression &&other) noexcept;
  WEAK_SYMBOL Expression &operator=(const Expression &other);
  WEAK_SYMBOL Expression &operator=(Expression &&other) noexcept;
  /**
   * @brief 获取表达式转换成字符串
   * @param type 字符串格式类型
   * @return 转换后的字符串，表达式非法时返回空指针
   */
  WEAK_SYMBOL std::unique_ptr<char_t[]> Str(const StrType type = StrType::kStrCpp) const;
  /**
   * @brief 序列化，将表达式转换成字符串
   * @return 序列化后的字符串，表达式非法时返回空指针
   */
  WEAK_SYMBOL std::unique_ptr<char_t[]> Serialize() const;

  /**
   * @brief
   * 反序列化，与Serialize接口匹配，将字符串转换成表达式，同时会校验字符串格式是否为序列化接口序列化出的字符串，如果不是则会报错
   * @param str Serialize接口产出的字符串
   * @return 反序列化出的表达式，字符串非法时返回非法表达式
   */
  WEAK_SYMBOL static Expression Deserialize(const char_t *str);

  /**
   * @brief 获取表达式的类型
   * @return 表达式类型
   */
  WEAK_SYMBOL ExprType GetExprType() const;
  /**
   * @brief 是否是ConstExpr类型
   * @return true/false
   */
  WEAK_SYMBOL bool IsConstExpr() const;

  /**
   * @brief 是否是Bool类型
   * @return true/false
   */
  WEAK_SYMBOL bool IsBooleanExpr() const;

  /**
   * @brief 对当前表达式中的符号进行替换，如对于表达式expr = x + y，expr.subs({x:2, y:z+1}) -> y + z +
   * 1。于repalce比较功能较单一， 只能替换单一符号，无法处理复杂的表达式
   * @param subs_vars 待替换的符号列表，pair中first为被替换的表达式，second为替换的表达式
   * @return 替换后表达式
   */
  WEAK_SYMBOL Expression Subs(const std::vector<std::pair<Expression, Expression>> &subs_vars) const;

  /**
   * @brief 对当前表达式进行化简。例如2+x+4 -> 6+x
   * @return 化简后的表达式
   */
  WEAK_SYMBOL Expression Simplify() const;

  /**
   * @brief 获取表达式的分子和分母，例如表达式Rational(2, 3) * s1，分子numer=2*s1，分母denom=3
   * @param numer 输出的分子表达式
   * @param denom 输出的分母表达式
   */
  WEAK_SYMBOL void AsNumerDenom(Expression &numer, Expression &denom) const;

  /**
   * @brief 判断两个Expr是否相等
   * @param e 另一个表达式
   * @return true/false
   */
  WEAK_SYMBOL bool operator==(const Expression &e) const;
  /**
   * @brief 判断一个expr与常量是否相等
   * @param e 常量
   * @return true/false
   */
  template <typename T>
  typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, bool>::type operator==(
      const T &e) const;

  /**
   * @brief 判断两个Expr是否不相等
   * @param e 另一个表达式
   * @return true/false
   */
  WEAK_SYMBOL bool operator!=(const Expression &e) const;

  /**
   * @brief 判断一个expr与常量是否不相等
   * @param e 常量
   * @return true/false
   */
  template <typename T>
  typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, bool>::type operator!=(
      const T &e) const;

  /**
   * @brief 获取表达式的参数，例如表达式 2*s0 + Pow(s1, 2)，函数返回[2*s0, Pow(s1, 2)]
   * @return 参数表达式列表
   */
  WEAK_SYMBOL std::vector<Expression> GetArgs();

  /**
   * @brief 获取表达式最基础的元素。例如x - (y * z)，返回{x, y, z}, 注意该接口没有依据字符去重
   * @return 基础元素列表
   */
  WEAK_SYMBOL std::vector<Expression> FreeSymbols() const;

  /**
   * @brief 对当前表达式中的表达式进行替换，例如 y= x+2. y.replace({x, 2*x}) -> y = 2*x + 2
   * @param replace_vars 替换规则列表，pair中first为被替换的表达式，second为替换的表达式
   * @return 替换后的表达式
   */
  WEAK_SYMBOL Expression Replace(const std::vector<std::pair<Expression, Expression>> &replace_vars) const;

  /**
   * @brief 判断表达式是否合法，成员变量impl_为null则不合法
   * @return true/false
   */
  WEAK_SYMBOL bool IsValid() const;

  /**
   * @brief 返回一个Expression类对象的hash值，主要目的是用于将Expression对象作为map的key时使用
   * @return hash值
   */
  WEAK_SYMBOL uint64_t Hash() const;

  /**
   * @brief 分别返回 -1, 0, 1 当 `this < e, this == e, this > e`.
   * @param e 另一个表达式
   * @return -1, 0, 1
   */
  WEAK_SYMBOL int64_t Compare(const Expression &e) const;

  /**
   * @brief 获取常量的值，只有GetExprType为kExprConstant时有效
   * @param value 常量的值
   * @return 成功返回true，失败返回false，失败时value的值无效
   */
  template <typename T>
  typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, bool>::type WEAK_SYMBOL
  GetConstValue(T &value) const;

  /**
   * @brief 获取表达式hint值
   * @param hint 获取表达式的hint值
   * @return 成功返回true，失败返回false，失败时value的值无效
   */
  template <typename T>
  typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, bool>::type GetHint(
      T &hint) const {
    return ComputeHint(hint);
  }

  WEAK_SYMBOL Expression operator+(const Expression &other) const;
  WEAK_SYMBOL Expression operator-(const Expression &other) const;
  WEAK_SYMBOL Expression operator*(const Expression &other) const;
  WEAK_SYMBOL Expression operator/(const Expression &other) const;

  friend Expression sym::Add(const Expression &a, const Expression &b);
  friend Expression sym::Sub(const Expression &a, const Expression &b);
  friend Expression sym::Mul(const Expression &a, const Expression &b);
  friend Expression sym::Div(const Expression &a, const Expression &b);
  friend Expression sym::Max(const Expression &a, const Expression &b);
  friend Expression sym::Min(const Expression &a, const Expression &b);
  friend Expression sym::Pow(const Expression &base, const Expression &exp);
  friend Expression sym::Exp(const Expression &a);
  friend Expression sym::Mod(const Expression &base, const Expression &exp);
  friend Expression sym::Abs(const Expression &a);
  friend Expression sym::Log(const Expression &a);  // 默认以E为底
  friend Expression sym::Log(const Expression &arg, const Expression &base);
  friend Expression sym::Coeff(const Expression &b, const Expression &x, const Expression &n);
  friend Expression sym::Rational(int32_t num, int32_t den);  // 分数
  friend Expression sym::Ceiling(const Expression &a);
  friend Expression sym::Floor(const Expression &arg);
  friend Expression sym::Align(const Expression &arg, uint32_t alignment);
  friend Expression sym::AlignWithPositiveInteger(const Expression &arg, uint32_t alignment);
  friend Expression sym::Eq(const Expression &a, const Expression &b);  // ==
  friend Expression sym::Ne(const Expression &a, const Expression &b);  // !=
  friend Expression sym::Ge(const Expression &a, const Expression &b);  // >=
  friend Expression sym::Gt(const Expression &a, const Expression &b);  // >
  friend Expression sym::Le(const Expression &a, const Expression &b);  // <=
  friend Expression sym::Lt(const Expression &a, const Expression &b);  // <
  friend Expression sym::Not(const Expression &a);                      // !
  friend Expression sym::Neg(const Expression &a);                      // 负号
  friend Expression sym::LogicalAnd(const std::vector<Expression> &a);
  friend Expression sym::LogicalOr(const std::vector<Expression> &a);
  friend std::ostream &operator<<(std::ostream &os, const Expression &e);
  friend class ShapeEnvAttr;

 protected:
  WEAK_SYMBOL explicit Expression(ExpressionImplPtr &&e);
  /**
   * @brief 获取表达式的hint值（内部接口，由GetHint调用）
   * @param hint 表达式的hint值
   * @return 成功返回true，失败返回false，失败时hint的值无效
   */
  template <typename T>
  typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, bool>::type WEAK_SYMBOL
  ComputeHint(T &hint) const;
  ExpressionImplPtr impl_;
};

class Symbol : public Expression {
 public:
  // 拷贝构造、赋值、移动构造、移动赋值默认使用基类，需要保证Symbol类大小与Expression类大小一致
  /**
   * @brief 创建常量
   * @param value 常量的值
   * @param name 常量的名称，默认为空，内部不持有该指针
   */
  WEAK_SYMBOL explicit Symbol(int32_t value, const char_t *name = "");
  WEAK_SYMBOL explicit Symbol(int64_t value, const char_t *name = "");
  WEAK_SYMBOL explicit Symbol(uint32_t value, const char_t *name = "");
  WEAK_SYMBOL explicit Symbol(uint64_t value, const char_t *name = "");
  WEAK_SYMBOL explicit Symbol(double value, const char_t *name = "");

  /**
   * @brief 创建变量
   * @param name 变量的名称
   */
  WEAK_SYMBOL explicit Symbol(const char_t *name = "");

  friend class ShapeEnvAttr;

 private:
  WEAK_SYMBOL explicit Symbol(ExpressionImplPtr &&e);
};

template <typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, bool>::type
Expression::operator==(const T &e) const {
  Symbol symbol(e);
  return (*this == symbol);
}

template <typename T>
typename std::enable_if<std::is_integral<T>::value || std::is_floating_point<T>::value, bool>::type
Expression::operator!=(const T &e) const {
  Symbol symbol(e);
  return !(*this == symbol);
}

// 为了保证ABI兼容性，禁用虚函数，Symbol的大小必须和Expression一样
static_assert(sizeof(Symbol) == sizeof(Expression),
              "The size of the subclass Symbol must be equal to the size of the base class Expression.");

namespace sym {
/**
 * @brief 校验两个表达式的hint相等性并生成guard，详见 EXPECT_SYMBOL_EQ 宏
 * @param e0 表达式0
 * @param e1 表达式1
 * @param file 调用位置的文件名
 * @param line 调用位置的行号
 * @return 校验通过返回true，否则返回false并生成guard
 */
WEAK_SYMBOL bool ExpectSymbolEq(const Expression &e0, const Expression &e1, const char_t *file, const int64_t line);
/**
 * @brief 校验两个表达式的hint相等性并生成guard，详见 ASSERT_SYMBOL_EQ 宏
 * @param e0 表达式0
 * @param e1 表达式1
 * @param file 调用位置的文件名
 * @param line 调用位置的行号
 * @return 校验通过返回true，否则返回false并生成guard
 */
WEAK_SYMBOL bool AssertSymbolEq(const Expression &e0, const Expression &e1, const char_t *file, const int64_t line);
/**
 * @brief 校验两个表达式的hint不相等并生成guard，详见 EXPECT_SYMBOL_NE 宏
 * @param e0 表达式0
 * @param e1 表达式1
 * @param file 调用位置的文件名
 * @param line 调用位置的行号
 * @return 校验通过返回true，否则返回false并生成guard
 */
WEAK_SYMBOL bool ExpectSymbolNe(const Expression &e0, const Expression &e1, const char_t *file, const int64_t line);
/**
 * @brief 校验表达式的hint可判定为真并生成guard，详见 EXPECT_SYMBOL_CHECK 宏
 * @param expr 待校验的表达式
 * @param file 调用位置的文件名
 * @param line 调用位置的行号
 * @return 校验通过返回true，否则返回false并生成guard
 */
WEAK_SYMBOL bool ExpectSymbolBool(const Expression &expr, const char_t *file, const int64_t line);
/**
 * @brief 校验表达式的hint可判定为真并生成guard，详见 ASSERT_SYMBOL_CHECK 宏
 * @param expr 待校验的表达式
 * @param file 调用位置的文件名
 * @param line 调用位置的行号
 * @return 校验通过返回true，否则返回false并生成guard
 */
WEAK_SYMBOL bool AssertSymbolBool(const Expression &expr, const char_t *file, const int64_t line);
}  // namespace sym
}  // namespace ge

/*
 * 校验表达式e0是否与e1相等
 * 如果e0的hint值与e1的hint值相等，则宏返回true，并生成e0 == e1的guard
 * 反之，则返回false，并生成 e0 != e1的guard
 */
#define EXPECT_SYMBOL_EQ(e0, e1) ge::sym::ExpectSymbolEq(e0, e1, __FILE__, __LINE__)

/*
 * 校验表达式e0是否与e1不相等
 * 如果e0的hint值与e1的hint值不相等，则宏返回true，并生成e0 != e1的guard
 * 反之，则返回false，并生成 e0 == e1的guard
 */
#define EXPECT_SYMBOL_NE(e0, e1) ge::sym::ExpectSymbolNe(e0, e1, __FILE__, __LINE__)

/*
 * 校验表达式e0是否小于e1
 * 如果e0的hint值小于e1的hint值，则宏返回true，并生成e0 < e1的guard
 * 反之，则返回false，并生成 e1 <= e0的guard
 */
#define EXPECT_SYMBOL_LT(e0, e1) EXPECT_SYMBOL_CHECK(ge::sym::Lt(e0, e1), __FILE__, __LINE__)

/*
 * 校验表达式e0是否小于等于e1
 * 如果e0的hint值小于等于e1的hint值，则宏返回true，并生成e0 <= e1的guard
 * 反之，则返回false，并生成 e1 < e0的guard
 */
#define EXPECT_SYMBOL_LE(e0, e1) EXPECT_SYMBOL_CHECK(ge::sym::Le(e0, e1), __FILE__, __LINE__)

/*
 * 校验表达式e0是否大于e1
 * 如果e0的hint值大于e1的hint值，则宏返回true，并生成e1 < e0的guard
 * 反之，则返回false，并生成 e0 <= e1的guard
 */
#define EXPECT_SYMBOL_GT(e0, e1) EXPECT_SYMBOL_CHECK(ge::sym::Gt(e0, e1), __FILE__, __LINE__)

/*
 * 校验表达式e0是否大于等于e1
 * 如果e0的hint值大于等于e1的hint值，则宏返回true，并生成e1 <= e0的guard
 * 反之，则返回false，并生成 e0 <= e1的guard
 */
#define EXPECT_SYMBOL_GE(e0, e1) EXPECT_SYMBOL_CHECK(ge::sym::Ge(e0, e1), __FILE__, __LINE__)

/*
 * 检查表达式列表是否都为true
 * 如果表达式都为true，则宏返回true，
 * 如果其中有一个是false，则返回false，否则并生成LogicAnd()的guard
 * 例如校验表达式：EXPECT_SYMBOL_AND(Ge(s0, s1), Le(s2, s3), Eq(s4, s5))
 * hint值为true时添加guard：LogicAnd(ExpectEq(s4, s5), ExpectLe(s1, s0), ExpectLe(s2, s3))
 * hint值为false时添加guard：LogicOr(ExpectLt(s0, s1), ExpectLt(s3, s2), ExpectNe(s4, s5))
 */
#define EXPECT_SYMBOL_AND(...) \
  EXPECT_SYMBOL_CHECK(ge::sym::LogicalAnd(std::vector<ge::Expression>{__VA_ARGS__}), __FILE__, __LINE__)

/*
 * 检查表达式列表是否有一个为true
 * 如果表达式全部为false，则宏返回false，
 * 如果其中有一个是true，则返回true，否则并生成LogicOr()的guard
 * 例如校验表达式：EXPECT_SYMBOL_OR(Ge(s0, s1), Le(s2, s3), Eq(s4, s5))
 * hint值为true时添加guard：LogicOr(ExpectEq(s4, s5), ExpectLe(s1, s0), ExpectLe(s2, s3))
 * hint值为false时添加guard：LogicAnd(ExpectLt(s0, s1), ExpectLt(s3, s2), ExpectNe(s4, s5))
 */
#define EXPECT_SYMBOL_OR(...) \
  EXPECT_SYMBOL_CHECK(ge::sym::LogicalOr(std::vector<ge::Expression>{__VA_ARGS__}), __FILE__, __LINE__)

/*
 * 强校验表达式e0是否等于e1
 * 如果e0的hint值等于e1的hint值，则生成e0 == e1的guard
 * 反之，则报错
 */
#define ASSERT_SYMBOL_EQ(e0, e1)                                \
  do {                                                          \
    if (!ge::sym::AssertSymbolEq(e0, e1, __FILE__, __LINE__)) { \
      return ge::GRAPH_PARAM_INVALID;                           \
    }                                                           \
  } while (false)

/*
 * 强校验表达式e0是否不等于e1
 * 如果e0的hint值不等于e1的hint值，则生成e0 != e1的guard
 * 反之，则报错
 */
#define ASSERT_SYMBOL_NE(e0, e1) ASSERT_SYMBOL_CHECK(ge::sym::Ne(e0, e1), __FILE__, __LINE__)

/*
 * 强校验表达式e0是否小于e1
 * 如果e0的hint值小于e1的hint值，则生成e0 < e1的guard
 * 反之，则报错
 */
#define ASSERT_SYMBOL_LT(e0, e1) ASSERT_SYMBOL_CHECK(ge::sym::Lt(e0, e1), __FILE__, __LINE__)

/*
 * 强校验表达式e0是否小于等于e1
 * 如果e0的hint值小于等于e1的hint值，则生成e0 <= e1的guard
 * 反之，则报错
 */
#define ASSERT_SYMBOL_LE(e0, e1) ASSERT_SYMBOL_CHECK(ge::sym::Le(e0, e1), __FILE__, __LINE__)

/*
 * 强校验表达式e0是否大于e1
 * 如果e0的hint值大于e1的hint值，则生成e1 < e0的guard
 * 反之，则报错
 */
#define ASSERT_SYMBOL_GT(e0, e1) ASSERT_SYMBOL_CHECK(ge::sym::Gt(e0, e1), __FILE__, __LINE__)

/*
 * 强校验表达式e0是否大于等于e1
 * 如果e0的hint值大于等于e1的hint值，则生成e1 <= e0的guard
 * 反之，则报错
 */
#define ASSERT_SYMBOL_GE(e0, e1) ASSERT_SYMBOL_CHECK(ge::sym::Ge(e0, e1), __FILE__, __LINE__)

#define EXPECT_SYMBOL_CHECK(expr, file, line) ge::sym::ExpectSymbolBool(expr, file, line)

#define ASSERT_SYMBOL_CHECK(expr, file, line)           \
  do {                                                  \
    if (!ge::sym::AssertSymbolBool(expr, file, line)) { \
      return ge::GRAPH_PARAM_INVALID;                   \
    }                                                   \
  } while (false)

namespace ge {
// 模板成员的显式实例化弱声明：定义在 symbolizer 库中，外部工程经弱引用使用，
// 避免在用户TU中因模板隐式需求产生强未定义符号
extern template WEAK_SYMBOL bool Expression::GetConstValue<int32_t>(int32_t &) const;
extern template WEAK_SYMBOL bool Expression::GetConstValue<uint32_t>(uint32_t &) const;
extern template WEAK_SYMBOL bool Expression::GetConstValue<int64_t>(int64_t &) const;
extern template WEAK_SYMBOL bool Expression::GetConstValue<uint64_t>(uint64_t &) const;
extern template WEAK_SYMBOL bool Expression::GetConstValue<double>(double &) const;
extern template WEAK_SYMBOL bool Expression::GetConstValue<float>(float &) const;
extern template WEAK_SYMBOL bool Expression::GetConstValue<bool>(bool &) const;

extern template WEAK_SYMBOL bool Expression::ComputeHint<int32_t>(int32_t &) const;
extern template WEAK_SYMBOL bool Expression::ComputeHint<uint32_t>(uint32_t &) const;
extern template WEAK_SYMBOL bool Expression::ComputeHint<int64_t>(int64_t &) const;
extern template WEAK_SYMBOL bool Expression::ComputeHint<uint64_t>(uint64_t &) const;
extern template WEAK_SYMBOL bool Expression::ComputeHint<double>(double &) const;
extern template WEAK_SYMBOL bool Expression::ComputeHint<float>(float &) const;
extern template WEAK_SYMBOL bool Expression::ComputeHint<bool>(bool &) const;

WEAK_SYMBOL std::ostream &operator<<(std::ostream &os, const Expression &e);

// Expression 容器 traits（供 unordered_map / map 以 Expression 为 key 使用）
struct ExpressionHash {
  uint64_t operator()(const Expression &k) const {
    return k.Hash();
  }
};
struct ExpressionKeyEq {
  bool operator()(const Expression &x, const Expression &y) const {
    return x == y;
  }
};
struct ExpressionKeyLess {
  bool operator()(const Expression &x, const Expression &y) const {
    int64_t xh = x.Hash();
    int64_t yh = y.Hash();
    if (xh != yh) return xh < yh;
    if (x == y) return false;
    return x.Compare(y) == -1;
  }
};

}  // namespace ge

#endif  // GRAPH_SYMBOLIZER_SYMBOLIC_H_
