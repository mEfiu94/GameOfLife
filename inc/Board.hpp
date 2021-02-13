#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "../inc/Entity.hpp"
using boardMatrix = std::vector<std::vector<Entity>>;
class Board {
 public:
  explicit Board(unsigned int width, unsigned int height) noexcept
      : entities_(width, std::vector<Entity>(height, StateOfEntity::Dead)),
        board_{sf::Vector2f(width, height)} {};

  sf::Vector2u getSize() const;
  const boardMatrix& GetElements() const;
  StateOfEntity GetStateAt(unsigned int x, unsigned int y) const;
  void SetStateAt(unsigned int x, unsigned int y, StateOfEntity state);
  void InvertStateAt(unsigned int x, unsigned int y);
 private:
  boardMatrix entities_;
  sf::RectangleShape board_;
};