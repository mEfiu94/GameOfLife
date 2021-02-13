#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>

#include "../inc/Renderer.hpp"
int main() {
  Board GameBoard(800, 600);
  Renderer Render(GameBoard);
  Render.showWindow();
  return 0;
}