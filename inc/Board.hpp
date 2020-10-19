#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Board
{
public:
    explicit Board(float width, float height) noexcept: board_{sf::Vector2f(width,height)}{};    
    sf::Vector2f getSize() const{return board_.getSize();};
    void display(sf::RenderWindow&);
private:    
    sf::RectangleShape board_;
};