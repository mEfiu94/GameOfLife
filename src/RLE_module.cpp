#include "../inc/RLE_module.hpp"

bool RLE_module::open(const char* filename){
  FileToRead_.open(filename,std::ios::in);
  return FileToRead_.is_open();
}