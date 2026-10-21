/**
 * Copyright (c) 2025 Huawei Technologies Co., Ltd.
 * This program is free software, you can redistribute it and/or modify it under the terms and conditions of
 * CANN Open Software License Agreement Version 2.0 (the "License").
 * Please refer to the License for details. You may not use this file except in compliance with the License.
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE.
 * See LICENSE in the root of the software repository for the full text of the License.
 */

#include <string.h>
#include <cstdio>
#include <fstream>
#include <limits>
#include "graph/utils/file_utils.h"
#include <gtest/gtest.h>
#include "graph/debug/ge_util.h"

namespace metadef {
class UtestFileUtils : public testing::Test {
 public:
 protected:
  void SetUp() {}
  void TearDown() {}
};

TEST_F(UtestFileUtils, RealPathIsNull) {
  const char *path = nullptr;
  std::string res;
  res = RealPath(path);
  EXPECT_EQ(res, "");
}

TEST_F(UtestFileUtils, RealPathIsNotExist) {
  const char *path = "D:/UTTest/aabbccddaaddbcasdaj.txt";
  std::string res;
  res = RealPath(path);
  EXPECT_EQ(res, "");
}

TEST_F(UtestFileUtils, CreateDirPathIsNull) {
  std::string directory_path;
  int32_t ret = CreateDir(directory_path);
  EXPECT_EQ(ret, -1);
}

TEST_F(UtestFileUtils, CreateDirSuccess) {
  std::string directory_path = "D:\\123\\456";
  int32_t ret = CreateDir(directory_path);
  EXPECT_EQ(ret, 0);
  int delete_ret = remove(directory_path.c_str());
  EXPECT_EQ(delete_ret, 0);
}

TEST_F(UtestFileUtils, CreateDirPathIsGreaterThanMaxPath) {
  std::string directory_path;
  for (int i = 0; i < 4000; i++) {
    directory_path.append(std::to_string(i));
  }
  int ret = 0;
  ret = CreateDir(directory_path);
  EXPECT_EQ(ret, -1);
}

TEST_F(UtestFileUtils, RealPath) {
  ASSERT_EQ(RealPath(nullptr), "");
}

TEST_F(UtestFileUtils, CreateDir) {
  ASSERT_EQ(CreateDir("~/test"), 0);
}

TEST_F(UtestFileUtils, GetBinFileFromFileSuccess) {
  std::string so_bin = "./opsptoro.so";
  system(("touch " + so_bin).c_str());
  system(("echo '123' > " + so_bin).c_str());
  uint32_t data_len;
  std::unique_ptr<ge::char_t[]> so_data = GetBinFromFile(so_bin, data_len);
  ASSERT_NE(so_data, nullptr);
  ASSERT_EQ(data_len, 4);
  ASSERT_EQ(so_data.get()[0], '1');
  ASSERT_EQ(so_data.get()[1], '2');
  ASSERT_EQ(so_data.get()[2], '3');

  system(("rm -f " + so_bin).c_str());
}

TEST_F(UtestFileUtils, GetBinDataFromFileRejectsSizeOverflow) {
  const std::string so_bin = "./get_bin_data_size_overflow_test.bin";
  std::ofstream ofs(so_bin, std::ios::binary | std::ios::trunc);
  ASSERT_TRUE(ofs.is_open());

  const std::streamoff file_size = static_cast<std::streamoff>(std::numeric_limits<uint32_t>::max()) + 5;
  ofs.write("data", 4);
  ofs.seekp(file_size - 1, std::ios::beg);
  ofs.put('x');
  ASSERT_TRUE(ofs.good());
  ofs.close();

  uint32_t data_len = 123U;
  const auto data = GetBinDataFromFile(so_bin, data_len);
  const int remove_result = std::remove(so_bin.c_str());
  EXPECT_EQ(data, nullptr);
  EXPECT_EQ(data_len, 0U);
  EXPECT_EQ(remove_result, 0);
}

TEST_F(UtestFileUtils, GetBinFileFromFileSuccess_offset) {
  std::string so_bin = "./opsptoro.so";
  system(("touch " + so_bin).c_str());
  system(("echo '123' > " + so_bin).c_str());
  size_t data_len = 4;
  size_t offset = 0;
  std::unique_ptr<ge::char_t[]> so_data = GetBinFromFile(so_bin, offset, data_len);
  ASSERT_NE(so_data, nullptr);
  ASSERT_EQ(data_len, 4);
  ASSERT_EQ(so_data.get()[0], '1');
  ASSERT_EQ(so_data.get()[1], '2');
  ASSERT_EQ(so_data.get()[2], '3');

  ASSERT_EQ(GetBinFromFile(so_bin, static_cast<ge::char_t *>(so_data.get()), data_len), ge::GRAPH_SUCCESS);
  ASSERT_NE(so_data, nullptr);
  ASSERT_EQ(data_len, 4);
  ASSERT_EQ(so_data.get()[0], '1');
  ASSERT_EQ(so_data.get()[1], '2');
  ASSERT_EQ(so_data.get()[2], '3');
  system(("rm -f " + so_bin).c_str());
}

TEST_F(UtestFileUtils, GetBinFilePathNullFail) {
  std::string so_bin = "";
  uint32_t data_len;
  std::unique_ptr<ge::char_t[]> so_data = GetBinFromFile(so_bin, data_len);
  ASSERT_EQ(so_data, nullptr);
}

TEST_F(UtestFileUtils, GetBinFileOpenPathFail) {
  std::string so_bin = "./opsptoro.so";
  uint32_t data_len;
  ASSERT_EQ(GetBinFromFile(so_bin, data_len), nullptr);
}

TEST_F(UtestFileUtils, WriteBinToFileSuccess) {
  std::string so_bin = "./opsptoro.so";
  uint32_t data_len = 4;
  char so_data[4] = {'1', '2', '3'};
  ASSERT_EQ(WriteBinToFile(so_bin, so_data, data_len), ge::GRAPH_SUCCESS);
  ASSERT_EQ(SaveBinToFile(so_data, data_len, so_bin), ge::GRAPH_SUCCESS);
  system(("rm -f " + so_bin).c_str());
}

TEST_F(UtestFileUtils, WriteBinToFilePathNullFail) {
  std::string so_bin = "";
  uint32_t data_len = 4;
  char so_data[4] = {'1', '2', '3'};
  ASSERT_EQ(WriteBinToFile(so_bin, so_data, data_len), ge::PARAM_INVALID);
}

TEST_F(UtestFileUtils, GetSanitizedNameCase0) {
  std::string file_name = "ge_proto_a/b\\c";
  ASSERT_EQ(GetRegulatedName(file_name), "ge_proto_a_b_c");
}

TEST_F(UtestFileUtils, SaveBinToFileWriteDataToFilePath) {
  std::string so_bin = "./save_bin_to_file.so";
  const char data[4] = {'a', 'b', 'c', 'd'};
  const size_t length = 4;
  ASSERT_EQ(SaveBinToFile(data, length, so_bin), ge::GRAPH_SUCCESS);

  uint32_t read_len = 0;
  std::unique_ptr<ge::char_t[]> read_data = GetBinFromFile(so_bin, read_len);
  ASSERT_NE(read_data, nullptr);
  ASSERT_EQ(read_len, length);
  ASSERT_EQ(read_data.get()[0], 'a');
  ASSERT_EQ(read_data.get()[1], 'b');
  ASSERT_EQ(read_data.get()[2], 'c');
  ASSERT_EQ(read_data.get()[3], 'd');

  system(("rm -f " + so_bin).c_str());
}
}  // namespace metadef
