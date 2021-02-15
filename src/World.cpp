#include "../inc/World.hpp"

StateOfEntity World::CheckNextStateOfCell(unsigned int x,
                                          unsigned int y) const {
  auto size_of_board = boardPtr_->getSize();
  auto x_min = 0, y_min = 0, x_max = static_cast<int>(size_of_board.x) - 1,
       y_max = static_cast<int>(size_of_board.y) - 1;
  auto liveCells = 0;
  if (static_cast<int>(x) - 1 >= x_min and static_cast<int>(y) - 1 >= y_min and
      boardPtr_->GetStateAt(x - 1u, y - 1u) == StateOfEntity::Alive)
    liveCells++;
  if (static_cast<int>(x) - 1 >= x_min and
      boardPtr_->GetStateAt(x - 1u, y) == StateOfEntity::Alive)
    liveCells++;
  if (static_cast<int>(x) - 1 >= x_min and static_cast<int>(y) + 1 <= y_max and
      boardPtr_->GetStateAt(x - 1u, y + 1u) == StateOfEntity::Alive)
    liveCells++;
  if (static_cast<int>(y) - 1 >= y_min and
      boardPtr_->GetStateAt(x, y - 1u) == StateOfEntity::Alive)
    liveCells++;
  if (static_cast<int>(y) + 1 <= y_max and
      boardPtr_->GetStateAt(x, y + 1u) == StateOfEntity::Alive)
    liveCells++;
  if (static_cast<int>(x) + 1 <= x_max and static_cast<int>(y) + 1 <= y_max and
      boardPtr_->GetStateAt(x + 1u, y + 1u) == StateOfEntity::Alive)
    liveCells++;
  if (static_cast<int>(x) + 1 <= x_max and
      boardPtr_->GetStateAt(x + 1u, y) == StateOfEntity::Alive)
    liveCells++;
  if (static_cast<int>(x) + 1 <= x_max and static_cast<int>(y) - 1 >= y_min and
      boardPtr_->GetStateAt(x + 1u, y - 1) == StateOfEntity::Alive)
    liveCells++;
  if (boardPtr_->GetStateAt(x, y) == StateOfEntity::Alive and
      (liveCells == 2 or liveCells == 3))
    return StateOfEntity::Alive;
  else if (boardPtr_->GetStateAt(x, y) == StateOfEntity::Dead and
           liveCells == 3)
    return StateOfEntity::Alive;
  else
    return StateOfEntity::Dead;
}
StateOfEntity World::CheckNextStateOfCell(const Entity& ent) const {
  return CheckNextStateOfCell(ent.getCoordinates().first,
                              ent.getCoordinates().second);
}
void World::EvaluateBoard() {
  Board nextBoard(boardPtr_->getSize().x,boardPtr_->getSize().y);
  for (auto& row : boardPtr_->GetElements())
    for (auto& cell : row) {
      nextBoard.SetStateAt(cell.getCoordinates().first,
                            cell.getCoordinates().second,
                            CheckNextStateOfCell(cell));
    }
  *boardPtr_=nextBoard;
}