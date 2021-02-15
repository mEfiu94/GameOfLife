#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "../inc/Entity.hpp"
using boardMatrix = std::vector<std::vector<Entity>>;
class Board {
 public:
  explicit Board(unsigned int width, unsigned int height) noexcept
      : entities_(width, std::vector<Entity>(height, Entity(StateOfEntity::Dead))),
        width_{width}, height_{height}{};

  [[nodiscard]] sf::Vector2u getSize() const;
  [[nodiscard]] const boardMatrix& GetElements() const;
  [[nodiscard]] StateOfEntity GetStateAt(unsigned int x, unsigned int y) const;
  void SetStateAt(unsigned int x, unsigned int y, StateOfEntity state);
  void InvertStateAt(unsigned int x, unsigned int y);
 private:
  boardMatrix entities_;
  unsigned int width_, height_;
};