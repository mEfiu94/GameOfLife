#pragma once
#include <memory>

#include "../inc/Board.hpp"
class Renderer {
 public:
  explicit Renderer(std::shared_ptr<Board>& board);
  Renderer() = delete;
  void updateRectangles();
  void showWindow();

 private:
  std::shared_ptr<Board> boardPtr_;
  sf::RenderWindow mainWindow_;
  std::vector<sf::RectangleShape> entitiesShapeVector_;
};