#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <random>

#include "../inc/Renderer.hpp"
int main() {
  Board GameBoard(192, 108);
  GameBoard.InvertStateAt(9, 0);
  Renderer Render(GameBoard);
  Render.showWindow();
  return 0;
}