#include <iostream>
#include <cmath>

int fast_divide(int a, int b) {
  if(a < b) return 0;
  if(a < b*2) return 1;
  int val = 0;
  int res = fast_divide(a, b*2);
  val += 1 + res;
  a = a - b * val;
  while(a >= b) {
    res = fast_divide(a, b);
    val += res;
    a = a - b * val;
  }
  return val;
}

int main(void)
{
  std::cout << fast_divide(18, 3) << std::endl;
  std::cout << fast_divide(529, 34) << std::endl;
  std::cout << fast_divide(180, 29) << std::endl;
  std::cout << fast_divide(17, 3) << std::endl;
  std::cout << fast_divide(9731, 14) << std::endl;
  std::cout << fast_divide(200, 10) << std::endl;
  
  return 0;
}
