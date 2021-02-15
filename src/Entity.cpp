#include "../inc/Entity.hpp"

std::pair<unsigned int, unsigned int> Entity::getCoordinates() const {
  return std::make_pair<>(x, y);
}