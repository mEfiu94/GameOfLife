#pragma once
#include <iostream>
#include <fstream>

class RLE_module{
  public:
    bool open(const char* filename);
  private:
    std::ifstream FileToRead_;
};
