#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../inc/Entity.hpp"
class Board
{
public:
    explicit Board(unsigned int width, unsigned int height) noexcept: board_{sf::Vector2f(width,height)},
                                                                        entities_(static_cast<size_t>(width*height),StateOfEntity::Dead){}; 
    sf::Vector2u getSize() const;
    const std::vector<Entity>& GetElements() const;    
private:    
    std::vector<Entity> entities_;
    sf::RectangleShape board_;
};