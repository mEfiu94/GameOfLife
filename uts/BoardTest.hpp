#pragma once
#include "../inc/Board.hpp"

class BoardTest : public ::testing::Test
{
protected:
public:
};

TEST_F(BoardTest, ShouldReturnBoardSizeWhereXIsWidthAndYIsHeight)
{
    float x = 10.f;
    float y = 20.f;
    sf::Vector2f size{x, y};
    Board plansza{x, y};
    ASSERT_NEAR(plansza.getSize().x, x, 0.00001);
    ASSERT_NEAR(plansza.getSize().y, y, 0.00001);
}

TEST_F(BoardTest, ShouldShowWindowWithGivenSize)
{
    float x = 700.f;
    float y = 700.f;
    sf::Vector2f size{x, y};
    Board plansza{x, y};
    sf::RenderWindow window(sf::VideoMode(plansza.getSize().x, plansza.getSize().y), "GameOfLife");
    sf::Event event;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        plansza.display(window);
    }
}
