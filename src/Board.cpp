#include "../inc/Board.hpp"

sf::Vector2u Board::getSize() const{
    sf::Vector2u boardUnsignedSize(0,0);
    boardUnsignedSize.x=board_.getSize().x;
    boardUnsignedSize.y=board_.getSize().y;
    return boardUnsignedSize;
}
const boardMatrix& Board::GetElements() const{
    return entities_;
}
const StateOfEntity Board::GetStateAt(unsigned int x, unsigned int y) const{
    StateOfEntity actualState=StateOfEntity::Dead;
    try
    {
        actualState=entities_.at(x).at(y).getState();
    }
    catch(std::out_of_range const& e)
    {              
        std::cerr << e.what() << '\n';       
        throw std::out_of_range("Coordinates are larger than board size in Board::GetStateAt()");        
    }
    return actualState;    
}
void Board::SetStateAt(unsigned int x, unsigned int y, StateOfEntity state){
    try{
        entities_.at(x).at(y).setState(state);
    }catch(std::out_of_range const& e){
        std::cerr << e.what() << '\n'; 
        throw std::out_of_range("Coordinates are larger than board size in Board::SetState()");
    }
}