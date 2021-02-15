#pragma once
#include "../inc/World.hpp"

class WorldTest : public ::testing::Test {
 protected:
  std::shared_ptr<Board> BoardPtr=std::make_shared<Board>(20,20);
  World TestWorld=World(BoardPtr);
  void SetUp() override{};
  void TearDown() override{};

 public:
  ~WorldTest() = default;
};
TEST_F(WorldTest, ShouldReturnTrueWhenCellIsGoingToSurvive) {
  EXPECT_EQ(StateOfEntity::Dead,TestWorld.CheckNextStateOfCell(0, 0));
  BoardPtr->SetStateAt(1,0,StateOfEntity::Alive);
  BoardPtr->SetStateAt(0,1,StateOfEntity::Alive);
  BoardPtr->SetStateAt(1,1,StateOfEntity::Alive);
  EXPECT_EQ(StateOfEntity::Dead,BoardPtr->GetStateAt(0,0));
  EXPECT_EQ(StateOfEntity::Alive,BoardPtr->GetStateAt(1,0));
  EXPECT_EQ(StateOfEntity::Alive,BoardPtr->GetStateAt(1,0));
  EXPECT_EQ(StateOfEntity::Alive,TestWorld.CheckNextStateOfCell(0, 0));
}