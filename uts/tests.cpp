#include <gtest/gtest.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "BoardTest.hpp"
#include "WorldTest.hpp"
#include "RLETest.hpp"
int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  std::cout << "TEST MAIN FILE" << std::endl;
  return RUN_ALL_TESTS();
}