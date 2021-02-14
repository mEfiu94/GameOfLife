#pragma once

#include "../inc/Board.hpp"
class Renderer {
 public:
  explicit Renderer(Board& board);
  Renderer() = delete;
  void updateRectangles();
  void showWindow();

 private:
  std::unique_ptr<Board> boardPtr_;
  sf::RenderWindow mainWindow_;
  std::vector<sf::RectangleShape> entitiesShapeVector_;
};