#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <random>

#include "../inc/Renderer.hpp"
#include "../inc/World.hpp"
int main() {
  auto BoardPtr = std::make_shared<Board>(75, 75);
  World TestWorld(BoardPtr);
  Renderer Render(BoardPtr);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(0, 74);
  std::uniform_int_distribution<> distrib2(0, 1);
  for (int i = 0; i <= 74*74; i++) {
    if (distrib2(gen))
      BoardPtr->SetStateAt(distrib(gen), distrib(gen), StateOfEntity::Alive);
    else
      BoardPtr->SetStateAt(distrib(gen), distrib(gen), StateOfEntity::Dead);
  }
  Render.showWindow();
  return 0;
}