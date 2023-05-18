#include <iostream>

// what will happen in the following function
void frame_count(int n) {
  std::cout << "Frame " << n << std::endl;
  char take_some_stack_space[512];
  frame_count(n + 1);
}

// try with regular compilation
// clang++ main.cpp
// and with optimisations turned on
// clang++ main.cpp -O3

int main() {
  frame_count(0);
}
