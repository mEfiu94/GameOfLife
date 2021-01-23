#pragma once
#include "../inc/Board.hpp"

class BoardTest : public ::testing::Test
{
protected:
public:
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

