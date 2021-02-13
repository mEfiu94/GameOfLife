#pragma once

#include "../inc/Board.hpp"
class Renderer {
 public:
  Renderer() = delete;
  explicit Renderer(Board& board) {
    mainWindow_.create(
        sf::VideoMode(board.getSize().x * 10, board.getSize().y * 10),
        "GameOfLife", sf::Style::Close);
    boardPtr_ = std::make_unique<Board>(board);
    mainWindow_.setFramerateLimit(60);
    for (size_t i = 0; i < (board.getSize().x); i++)
      for (size_t j = 0; j < (board.getSize().y); j++) {
        auto shape = sf::RectangleShape(sf::Vector2f(10.0f, 10.0f));
        shape.setFillColor(sf::Color::White);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(-0.5f);
        shape.setPosition(10.f * i, 10.f * j);
        entitiesShapeVector_.push_back(shape);
      }
  }
  void updateRectangles() {
    auto iter = std::begin(entitiesShapeVector_);
    for (auto elem : boardPtr_->GetElements())
      for (auto elem2 : elem) {
        if (elem2.getState() == StateOfEntity::Dead) {
          iter->setFillColor(sf::Color::Black);
        } else {
          iter->setFillColor(sf::Color::White);
        }
        iter->setOutlineColor(sf::Color::White);
        if (iter <= std::end(entitiesShapeVector_))
          ++iter;
        else
          return;
      }
  }
  void showWindow() {
    while (mainWindow_.isOpen()) {
      sf::Event event;
      while (mainWindow_.pollEvent(event)) {
        if (event.type == sf::Event::Closed) mainWindow_.close();
      }
      mainWindow_.clear(sf::Color::Black);
      updateRectangles();
      for (auto elem : entitiesShapeVector_) mainWindow_.draw(elem);
      mainWindow_.display();
    }
  }

 private:
  std::unique_ptr<Board> boardPtr_;
  sf::RenderWindow mainWindow_;
  std::vector<sf::RectangleShape> entitiesShapeVector_;
};