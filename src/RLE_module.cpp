#include "../inc/RLE_module.hpp"

#include <cstdlib>
#include <regex>
bool RLE_module::open(const char* filename) {
  FileToRead_.open(filename, std::ios::in);
  return FileToRead_.is_open();
}
void RLE_module::ParseCharacter(const std::string line,
                                std::vector<Entity>& final_vector) const {
  unsigned int x = 0, y = 0;
  std::string StringNoCells = "";
  int noOfCells = 1;
  for (auto i = line.begin(); i < line.end(); i++) {
    auto character = *i;
    switch (character) {
      case 'b':
        if (StringNoCells != "") noOfCells = std::stoi(StringNoCells);
        for (auto j = 0; j < noOfCells; j++) {
          final_vector.push_back(Entity(StateOfEntity::Dead, x, y));
          x++;
        }
        noOfCells = 1;
        StringNoCells = "";
        break;
      case 'o':
        if (StringNoCells != "") noOfCells = std::stoi(StringNoCells);
        for (auto j = 0; j < noOfCells; j++) {
          final_vector.push_back(Entity(StateOfEntity::Alive, x, y));
          x++;
        }
        noOfCells = 1;
        StringNoCells = "";
        break;
      case '$':
        x = 0;
        y++;
        break;
      case '!':
        break;
      default:
        while (i != line.end()) {
          StringNoCells += *i;
          if (((i + 1) != line.end() and *(i + 1) != 'b' and *(i + 1) != '!' and
               *(i + 1) != 'o' and *(i + 1) != '$'))
            i++;
          else
            break;
        }
        break;
    }
  }
}
std::vector<Entity> RLE_module::parse() {
  std::vector<Entity> final_vector;
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
            break;
          case 1:
            height = std::stoul(number);
            break;
        }
        if (i != reg_end) i++;
      }
    } else if (!line.starts_with('#')) {
      ParseCharacter(line, final_vector);
    }
  }
  return final_vector;
}