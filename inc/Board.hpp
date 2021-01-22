#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Board
{
public:
    explicit Board(unsigned int width, unsigned int height) noexcept: board_{sf::Vector2f(width,height)}{}; 
    sf::Vector2u getSize() const;
    void display(sf::RenderWindow&);
private:    
    sf::RectangleShape board_;
};