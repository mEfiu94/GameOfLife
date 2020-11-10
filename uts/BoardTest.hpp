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

TEST_F(BoardTest, ShouldShowWindowWithGivenSize)
{
    unsigned int x = 200;
    unsigned int y = 200;
    sf::Vector2u size{x, y};
    Board plansza{x, y};
    sf::RenderWindow window(sf::VideoMode(plansza.getSize().x, plansza.getSize().y), "GameOfLife",sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;
    ASSERT_EQ(window.getSize(),size);
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
