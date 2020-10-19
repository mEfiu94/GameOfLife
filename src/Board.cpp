#include "../inc/Board.hpp"

void Board::display(sf::RenderWindow& window){
    window.clear();
    window.draw(board_);
    window.display();    
}