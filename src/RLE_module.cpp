#include "../inc/RLE_module.hpp"

#include <cstdlib>
#include <regex>
bool RLE_module::open(const char* filename) {
  FileToRead_.open(filename, std::ios::in);
  return FileToRead_.is_open();
}
std::vector<Entity> RLE_module::parse() {
  std::string line;
  auto numbers_regex =
      std::regex("\\b([1-9]|[1-9][0-9]|[1-9][0-9][0-9]|1000)\\b");
  while (!FileToRead_.eof()) {
    std::getline(FileToRead_, line);
    if (line.starts_with('x')) {
      auto reg_begin =
          std::sregex_iterator(line.begin(), line.end(), numbers_regex);
      auto reg_end = std::sregex_iterator();
      auto i = reg_begin;
      for (auto k = 0; k < 2; k++) {
        std::smatch match = *i;
        const std::string number = match.str();
        switch (k) {
          case 0:
            width = std::stoul(number);
          case 1:
            height = std::stoul(number);
        }
        if (i != reg_end) i++;
      }
    }
  }
  return std::vector<Entity>();
}