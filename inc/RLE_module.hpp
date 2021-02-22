#pragma once
#include <fstream>
#include <iostream>
#include <vector>

#include "../inc/Entity.hpp"
class RLE_module {
 public:
  bool open(const char* filename);
  std::vector<Entity> parse();
  unsigned int GetWidth() const { return width; };
  unsigned int GetHeight() const { return height; };

 private:
  unsigned int width = 0, height = 0;
  std::ifstream FileToRead_;
};
