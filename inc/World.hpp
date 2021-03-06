#pragma once
#include <memory>

#include "../inc/Board.hpp"
class World {
 public:
  explicit World(std::shared_ptr<Board>& board) : boardPtr_(board){};
  StateOfEntity CheckNextStateOfCell(unsigned int, unsigned int) const;
  StateOfEntity CheckNextStateOfCell(const Entity&) const;
  void EvaluateBoard();

 private:
  std::shared_ptr<Board> boardPtr_;
};