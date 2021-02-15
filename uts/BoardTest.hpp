#pragma once
#include "../inc/Board.hpp"

class BoardTest : public ::testing::Test {
 protected:
  Board TestBoard = Board{10u, 20u};
  void SetUp() override{};
  void TearDown() override{};

 public:
  ~BoardTest() = default;
};

TEST_F(BoardTest, ShouldReturnBoardSizeWhereXIsWidthAndYIsHeight) {
  unsigned int x = 10;
  unsigned int y = 20;
  sf::Vector2<unsigned int> size{x, y};
  Board plansza{x, y};
  ASSERT_NEAR(plansza.getSize().x, x, 0.00001);
  ASSERT_NEAR(plansza.getSize().y, y, 0.00001);
}
TEST_F(BoardTest, ShouldReturnVectorOfEntities) {
  const boardMatrix entities(
      10, std::vector<Entity>(20, Entity(StateOfEntity::Dead)));
  EXPECT_EQ(TestBoard.GetElements(), entities);
}
TEST_F(BoardTest, ShouldReturnDeadStateOfEntityAtSpecifiedCoordinates) {
  auto actualState = TestBoard.GetStateAt(1u, 1u);
  EXPECT_EQ(StateOfEntity::Dead, actualState);
  EXPECT_NE(StateOfEntity::Alive, actualState);
}
TEST_F(BoardTest, ShouldSetStateOfEntityAsAlive) {
  TestBoard.SetStateAt(1u, 1u, StateOfEntity::Alive);
  EXPECT_EQ(StateOfEntity::Alive, TestBoard.GetStateAt(1u, 1u));
  EXPECT_EQ(StateOfEntity::Dead, TestBoard.GetStateAt(0u, 0u));
}
TEST_F(BoardTest, ShouldThrowAnExceptionWhenGettingOutOfRange) {
  EXPECT_THROW(TestBoard.GetStateAt(10, 9), std::out_of_range);
  EXPECT_NO_THROW(TestBoard.GetStateAt(9, 9));
}
TEST_F(BoardTest, ShouldThrowAnExceptionWhenSettingOutOfRange) {
  EXPECT_THROW(TestBoard.SetStateAt(10, 9, StateOfEntity::Alive),
               std::out_of_range);
  EXPECT_NO_THROW(TestBoard.SetStateAt(9, 9, StateOfEntity::Alive));
}