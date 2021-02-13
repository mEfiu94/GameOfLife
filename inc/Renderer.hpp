#pragma once

#include "../inc/Board.hpp"
class Renderer {
 public:
  Renderer() = delete;
  explicit Renderer(Board& board) {
    mainWindow_.create(sf::VideoMode(board.getSize().x, board.getSize().y),
                       "GameOfLife", sf::Style::Close);
    boardPtr_ = std::make_shared<Board>(board);
    mainWindow_.setFramerateLimit(144);
  }
  void showWindow() {
    while (mainWindow_.isOpen()) {
      sf::Event event;
      while (mainWindow_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) mainWindow_.close();
      }
      mainWindow_.clear(sf::Color::Black);            
      mainWindow_.display();
    }
  }

 private:
  std::shared_ptr<Board> boardPtr_;
  sf::RenderWindow mainWindow_; 
};