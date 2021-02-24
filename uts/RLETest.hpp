#pragma once

#include "../inc/Entity.hpp"
#include "../inc/RLE_module.hpp"

class RLETest : public ::testing::Test {
 protected:
  RLE_module module;
  void SetUp() override{};
  void TearDown() override{};

 public:
  ~RLETest() = default;
};

TEST_F(RLETest, ShouldReturnTrueIfFileIsPresentAndOpened) {
  EXPECT_EQ(RLETest::module.open("Glider.rle"), true);
}
TEST_F(RLETest, ShouldReturnFalseIfFileIsNotPresentOrOpened) {
  EXPECT_EQ(RLETest::module.open("test.rle"), false);
}
TEST_F(RLETest, ShouldIgnoreHashBeginingLines) {
  module.open("HashTestFile.rle");
  auto vec = RLETest::module.parse();
  EXPECT_EQ(vec, std::vector<Entity>());
}
TEST_F(RLETest, ShouldSaveWidthAndHeightOfPattern) {
  module.open("Glider.rle");
  RLETest::module.parse();
  EXPECT_EQ(module.GetWidth(), 3u);
  EXPECT_EQ(module.GetHeight(), 3u);
}
TEST_F(RLETest, ShouldReturnDecodedVectorOfEntites) {
  module.open("Glider.rle");
  std::vector<Entity> test_vector;
  test_vector.push_back(Entity(StateOfEntity::Dead, 0, 0));
  test_vector.push_back(Entity(StateOfEntity::Alive, 1, 0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 0, 1));
  test_vector.push_back(Entity(StateOfEntity::Dead, 1, 1));
  test_vector.push_back(Entity(StateOfEntity::Alive, 2, 1));
  test_vector.push_back(Entity(StateOfEntity::Alive, 0, 2));
  test_vector.push_back(Entity(StateOfEntity::Alive, 1, 2));
  test_vector.push_back(Entity(StateOfEntity::Alive, 2, 2));
  auto vec = module.parse();
  EXPECT_EQ(test_vector.size(),vec.size());
  for(size_t i=0;i<test_vector.size();i++)
  {
    EXPECT_EQ(test_vector[i],vec[i]);
  }
}
TEST_F(RLETest,ShouldReadMultiDigitsFromRLEFile){
  module.open("GosperGliderGun.rle");
  auto final_vec=module.parse();
  EXPECT_EQ(module.GetHeight(),9);
  EXPECT_EQ(module.GetWidth(),36);  
}
TEST_F(RLETest,ShouldReadMultiDigitsVectorConfiguration){
  module.open("MultipleDigitTest.rle");
  auto vec=module.parse();
  std::vector<Entity> test_vector;
  test_vector.push_back(Entity(StateOfEntity::Dead, 0,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 1,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 2,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 3,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 4,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 5,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 6,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 7,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 8,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 9,0));
  test_vector.push_back(Entity(StateOfEntity::Dead, 10,0));
  test_vector.push_back(Entity(StateOfEntity::Alive, 11,0));
  test_vector.push_back(Entity(StateOfEntity::Alive, 12,0));
  EXPECT_EQ(test_vector.size(),vec.size());
  for(size_t i=0;i<test_vector.size();i++)
  {
    EXPECT_EQ(test_vector[i],vec[i]);
  }
}