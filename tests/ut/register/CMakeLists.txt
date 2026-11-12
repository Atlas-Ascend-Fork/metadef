# -----------------------------------------------------------------------------------------------------------
# Copyright (c) 2025 Huawei Technologies Co., Ltd.
# This program is free software, you can redistribute it and/or modify it under the terms and conditions of
# CANN Open Software License Agreement Version 2.0 (the "License").
# Please refer to the License for details. You may not use this file except in compliance with the License.
# THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
# INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
# See LICENSE in the root of the software repository for the full text of the License.
# -----------------------------------------------------------------------------------------------------------

# include directories
include_directories(${CMAKE_CURRENT_LIST_DIR})
include_directories(${CMAKE_BINARY_DIR}/proto/ge)
include_directories(${CMAKE_BINARY_DIR}/proto/metadef_protos)
include_directories(${CMAKE_BINARY_DIR}/proto/metadef_protos/proto)
include_directories(${METADEF_DIR})
include_directories(${METADEF_DIR}/pkg_inc)
include_directories(${METADEF_DIR}/register)
include_directories(${METADEF_DIR}/inc/external)
include_directories(${METADEF_DIR}/inc/external/asc)

file(GLOB_RECURSE REGISTER_UT_FILES CONFIGURE_DEPENDS "${METADEF_DIR}/tests/ut/register/*.cc" )

# 弱 fallback 看护 TU 依赖「进程内无强定义」，须与链接注册库的 ut_register 隔离
list(REMOVE_ITEM REGISTER_UT_FILES
        "${METADEF_DIR}/tests/ut/register/testcase/infer_symbol_weak_fallback_unittest.cc")

add_executable(ut_register
    ${REGISTER_UT_FILES}
)
add_compile_definitions(CMAKE_BINARY_DIR=\"${CMAKE_BINARY_DIR}\")
target_compile_options(ut_register PRIVATE
    -g --coverage -fprofile-arcs -ftest-coverage -fno-access-control
    -Wno-deprecated-declarations
    -Wall -Wfloat-equal -Werror
    -Wno-unused-parameter
    -fno-access-control
)

target_compile_definitions(ut_register PRIVATE
    google=ascend_private
)

target_link_libraries(ut_register
    metadef_intf_pub
    metadef_headers
    runtime_headers
    slog_headers
    msprof_headers
    metadef exe_graph mmpa
    opp_registry
    tilingdata_base
    GTest::gtest
    GTest::gtest_main
    pthread
    ascend_protobuf
    slog_stub
    platform_stub
    c_sec
    error_manager
    mmpa_stub
    -lrt
    -ldl
    -lgcov
    -Wl,--whole-archive
    rt2_registry_static
    -Wl,--no-whole-archive
)

target_link_options(ut_register PRIVATE
        -Wl,--disable-new-dtags
        -Wl,-rpath,${CMAKE_CURRENT_LIST_DIR}
        )

target_include_directories(ut_register PRIVATE
        ${METADEF_DIR}/base/registry
        )

add_test(NAME ut_register COMMAND ut_register --gtest_output=xml:${CMAKE_INSTALL_PREFIX}/report/ut/ut_register.xml)
set_tests_properties(ut_register PROPERTIES LABELS "ut;ut_register")

# -----------------------------------------------------------------------------------------------------------
# ut_infer_symbol_weak_fallback：弱符号 fallback 行为看护（独立可执行，不链接注册库）
# 本目标编译链接通过即证明 InferSymbol 系接口的弱声明+头内 fallback 机制完整
# （删除弱化或 fallback 将直接编译失败）；运行期仅 fallback 定义可达，
# 覆盖「新算子 so 在老 GE 环境」宏式/OpDef 式注册静默降级的行为语义
# -----------------------------------------------------------------------------------------------------------
add_executable(ut_infer_symbol_weak_fallback
        ${METADEF_DIR}/tests/ut/register/testcase/infer_symbol_weak_fallback_unittest.cc
)
target_compile_options(ut_infer_symbol_weak_fallback PRIVATE
        -g -Wall -Werror -Wno-unused-parameter -Wno-deprecated-declarations -Wno-float-equal
)
target_compile_definitions(ut_infer_symbol_weak_fallback PRIVATE
        google=ascend_private
)
target_link_libraries(ut_infer_symbol_weak_fallback
        metadef_intf_pub
        metadef_headers
        runtime_headers
        slog_headers
        msprof_headers
        GTest::gtest
        GTest::gtest_main
        pthread
)

add_test(NAME ut_infer_symbol_weak_fallback
        COMMAND ut_infer_symbol_weak_fallback
        --gtest_output=xml:${CMAKE_INSTALL_PREFIX}/report/ut/ut_infer_symbol_weak_fallback.xml)
set_tests_properties(ut_infer_symbol_weak_fallback PROPERTIES LABELS "ut;ut_infer_symbol_weak_fallback")
