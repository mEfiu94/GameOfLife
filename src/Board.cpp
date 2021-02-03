#include "../inc/Board.hpp"

sf::Vector2u Board::getSize() const{
    sf::Vector2u boardUnsignedSize(0,0);
    boardUnsignedSize.x=board_.getSize().x;
    boardUnsignedSize.y=board_.getSize().y;
    return boardUnsignedSize;
} 
const std::vector<Entity>& Board::GetElements() const{
    return entities_;
}