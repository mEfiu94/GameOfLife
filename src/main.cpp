#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <random>

#include "../inc/Renderer.hpp"
#include "../inc/World.hpp"
#include "../inc/RLE_module.hpp"
int main() {
  auto BoardPtr = std::make_shared<Board>(120, 120);
  World TestWorld(BoardPtr);
  Renderer Render(BoardPtr);
  auto modulePtr = std::make_unique<RLE_module>();
  modulePtr->open("GosperGliderGun.rle");
  BoardPtr->AddPattern(modulePtr,20,50);
  Render.showWindow();
  return 0;
}