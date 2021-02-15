#pragma once
#include "../inc/Renderer.hpp"
#include "../inc/World.hpp"
class WorldTest : public ::testing::Test {
 protected:
  std::shared_ptr<Board> BoardPtr = std::make_shared<Board>(20, 20);
  World TestWorld = World(BoardPtr);
  void SetUp() override{};
  void TearDown() override{};

 public:
  ~WorldTest() = default;
};
TEST_F(WorldTest, ShouldReturnAliveWhenDeadCellHasThreeAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Alive, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnAliveWhenAliveCellHasTwoAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);

  EXPECT_EQ(StateOfEntity::Alive, TestWorld.CheckNextStateOfCell(1, 1));
}

TEST_F(WorldTest, ShouldReturnAliveWhenAliveCellHasThreeAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Alive, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenDeadCellHasFourAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Alive);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenDeadCellHasFiveAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenDeadCellHasSixAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenDeadCellHasSevenAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenDeadCellHasAllAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Alive);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenAliveCellHasFourAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Alive);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenAliveCellHasFiveAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenAliveCellHasSixAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenAliveCellHasSevenAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenAliveCellHasAllAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Alive);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenAliveCellHasZeroAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnDeadWhenAliveCellHasOneAliveNeighbours) {
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 0, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Dead, TestWorld.CheckNextStateOfCell(1, 1));
}
TEST_F(WorldTest, ShouldReturnAliveWhenAliveCellHasTwoAliveNeighboursCorner) {
  BoardPtr->SetStateAt(19, 19, StateOfEntity::Alive);
  BoardPtr->SetStateAt(18, 19, StateOfEntity::Alive);
  BoardPtr->SetStateAt(19, 18, StateOfEntity::Alive);
  BoardPtr->SetStateAt(0, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(1, 2, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 0, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Dead);
  BoardPtr->SetStateAt(2, 2, StateOfEntity::Dead);
  EXPECT_EQ(StateOfEntity::Alive, TestWorld.CheckNextStateOfCell(19, 19));
}
TEST_F(WorldTest, ShouldNotChangeTheBoardAfterOneTickWhenUsingBlockPattern){
  BoardPtr->SetStateAt(9, 9, StateOfEntity::Alive);
  BoardPtr->SetStateAt(10, 9, StateOfEntity::Alive);
  BoardPtr->SetStateAt(9, 10, StateOfEntity::Alive);
  BoardPtr->SetStateAt(10, 10, StateOfEntity::Alive);
  TestWorld.EvaluateBoard(); 
  EXPECT_EQ(BoardPtr->GetStateAt(9,9),StateOfEntity::Alive);
  EXPECT_EQ(BoardPtr->GetStateAt(10,9),StateOfEntity::Alive);
  EXPECT_EQ(BoardPtr->GetStateAt(9,10),StateOfEntity::Alive);
  EXPECT_EQ(BoardPtr->GetStateAt(10,10),StateOfEntity::Alive);
  EXPECT_EQ(BoardPtr->GetStateAt(8,8),StateOfEntity::Dead);  
}
TEST_F(WorldTest, ShouldChangeTheBoardAfterOneTickWhenUsingBlinkerPattern){
  BoardPtr->SetStateAt(0, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(1, 1, StateOfEntity::Alive);
  BoardPtr->SetStateAt(2, 1, StateOfEntity::Alive); 
  TestWorld.EvaluateBoard(); 
  EXPECT_EQ(BoardPtr->GetStateAt(0,1),StateOfEntity::Dead);
  EXPECT_EQ(BoardPtr->GetStateAt(1,1),StateOfEntity::Alive);
  EXPECT_EQ(BoardPtr->GetStateAt(2,1),StateOfEntity::Dead);
  EXPECT_EQ(BoardPtr->GetStateAt(1,0),StateOfEntity::Alive);
  EXPECT_EQ(BoardPtr->GetStateAt(1,2),StateOfEntity::Alive);     
}
