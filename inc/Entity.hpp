#pragma once
enum StateOfEntity {
  Alive,
  Dead,
};
class Entity {
 public:
  explicit Entity(StateOfEntity birthState) : state_{birthState} {};
  [[nodiscard]] StateOfEntity getState() const { return state_; };
  void setState(StateOfEntity newState) { state_ = newState; };
  bool operator==(const Entity b) const { return getState() == b.getState(); }
 private:
  StateOfEntity state_;
};
