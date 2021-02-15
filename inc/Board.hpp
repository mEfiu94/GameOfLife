#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "../inc/Entity.hpp"
using boardMatrix = std::vector<std::vector<Entity>>;
class Board {
 public:
  explicit Board(unsigned int width, unsigned int height) noexcept
      : width_{width}, height_{height} {
    for (size_t i = 0; i < width; i++) {
      std::vector<Entity> temp;
      for (size_t j = 0; j < height; j++)
        temp.push_back(Entity(StateOfEntity::Dead, i, j));
      entities_.push_back(temp);
    }
  };

  [[nodiscard]] sf::Vector2u getSize() const;
  [[nodiscard]] const boardMatrix& GetElements() const;
  [[nodiscard]] StateOfEntity GetStateAt(unsigned int x, unsigned int y) const;
  void SetStateAt(unsigned int x, unsigned int y, StateOfEntity state);
  void InvertStateAt(unsigned int x, unsigned int y);

 private:
  boardMatrix entities_;
  unsigned int width_, height_;
};