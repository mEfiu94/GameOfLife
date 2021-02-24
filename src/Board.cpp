#include "../inc/Board.hpp"

sf::Vector2u Board::getSize() const {
  sf::Vector2u boardUnsignedSize(0, 0);
  boardUnsignedSize.x = width_;
  boardUnsignedSize.y = height_;
  return boardUnsignedSize;
}
const boardMatrix& Board::GetElements() const { return entities_; }
StateOfEntity Board::GetStateAt(unsigned int x, unsigned int y) const {
  StateOfEntity actualState = StateOfEntity::Dead;
  try {
    actualState = entities_.at(x).at(y).getState();
  } catch (std::out_of_range const& e) {
    std::cerr << e.what() << '\n';
    throw std::out_of_range(
        "Coordinates are larger than board size in Board::GetStateAt()");
  }
  return actualState;
}
void Board::SetStateAt(unsigned int x, unsigned int y, StateOfEntity state) {
  try {
    entities_.at(x).at(y).setState(state);
  } catch (std::out_of_range const& e) {
    std::cerr << e.what() << '\n';
    throw std::out_of_range(
        "Coordinates are larger than board size in Board::SetState()");
  }
}
void Board::InvertStateAt(unsigned int x, unsigned int y) {
  try {
    if (entities_.at(x).at(y).getState() == StateOfEntity::Dead)
      SetStateAt(x, y, StateOfEntity::Alive);
    else
      SetStateAt(x, y, StateOfEntity::Dead);
  } catch (std::out_of_range const& e) {
    std::cerr << e.what() << '\n';
    throw std::out_of_range(
        "Coordinates are larger than board size in Board::InvertState()");
  }
}

void Board::AddPattern(const std::unique_ptr<RLE_module>& modulePtr,
                       unsigned int x, unsigned int y) {
  auto vec = modulePtr->parse();
  for (auto entity : vec) {
    Entity movedEntity(entity.getState(), entity.getCoordinates().first + x,
                       entity.getCoordinates().second + y);
    for (auto& vector : entities_) {
      std::replace_if(
          vector.begin(), vector.end(),
          [&](auto& elem) {
            return elem.getCoordinates().first ==
                       movedEntity.getCoordinates().first and
                   elem.getCoordinates().second ==
                       movedEntity.getCoordinates().second;
          },
          movedEntity);
    }
  }
}
