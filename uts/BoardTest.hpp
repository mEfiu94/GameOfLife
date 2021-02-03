#pragma once
#include "../inc/Board.hpp"

class BoardTest : public ::testing::Test
{
protected:
    void SetUp() override{};
    void TearDown() override{};
public:
    ~BoardTest()=default;
};

TEST_F(BoardTest, ShouldReturnBoardSizeWhereXIsWidthAndYIsHeight)
{
    unsigned int x = 10;
    unsigned int y = 20;
    sf::Vector2 size{x, y};
    Board plansza{x, y};
    ASSERT_NEAR(plansza.getSize().x, x, 0.00001);
    ASSERT_NEAR(plansza.getSize().y, y, 0.00001);
}
TEST_F(BoardTest, ShouldReturnVectorOfEntities)
{
    Board TestBoard{10u,10u};
    const std::vector<Entity> entities(100,StateOfEntity::Dead);
    EXPECT_EQ(TestBoard.GetElements(),entities);
}
