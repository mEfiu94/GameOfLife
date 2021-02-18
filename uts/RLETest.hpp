#pragma once
#include "../inc/RLE_module.hpp"

class RLETest : public ::testing::Test {
 protected:  
  RLE_module module;
  void SetUp() override{};
  void TearDown() override{};

 public:
  ~RLETest() = default;
};

TEST_F(RLETest, ShouldReturnTrueIfFileIsPresentAndOpened){
  EXPECT_EQ(RLETest::module.open("Glider.rle"),true);
}
TEST_F(RLETest, ShouldReturnFalseIfFileIsNotPresentOrOpened){
  EXPECT_EQ(RLETest::module.open("test.rle"),false);
}