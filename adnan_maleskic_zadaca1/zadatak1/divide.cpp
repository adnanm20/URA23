#include <iostream>

int divide(int a, int b) {
  if(a < b) return 0;
  return 1 + divide(a-b, b);
}

int main(void)
{
  std::cout << divide(204, 34) << std::endl;
  std::cout << divide(14, 3) << std::endl;
  std::cout << divide(304, 17) << std::endl;
  std::cout << divide(352, 94) << std::endl;
  
  return 0;
}
