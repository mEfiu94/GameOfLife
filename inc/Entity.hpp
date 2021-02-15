#pragma once
#include <utility>

enum StateOfEntity {
  Alive,
  Dead,
};
class Entity {
 public:
  explicit Entity(StateOfEntity birthState, unsigned int x_new,
                  unsigned int y_new)
      : state_{birthState}, x{x_new}, y{y_new} {};
  [[nodiscard]] StateOfEntity getState() const { return state_; };
  void setState(StateOfEntity newState) { state_ = newState; };
  bool operator==(const Entity b) const { return getState() == b.getState(); }
  std::pair<unsigned int, unsigned int> getCoordinates()const;

 private:
  StateOfEntity state_;
  unsigned int x;
  unsigned int y;
};
