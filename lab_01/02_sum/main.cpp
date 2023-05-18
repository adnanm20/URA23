#include <iostream>
#include <chrono>

// implement a recursive function that adds two numbers
// suppose your computer only know how to increment or decrement a number
int sum(int n, int a) {
  if(a == 0) return n;
  return sum(++n, --a);
}

// this recursion does not use stack space (expect from the minimal amound
// needed by the compiler) it is pretty easy for the compiler to optimise out
// the recursion
// sum(4, 3)
// sum(3, 4)
// sum(2, 5)
// sum(1, 6)
// 7

int main() {
  std::cout << "5 + 3 = " << sum(5, 3) << std::endl;
  std::cout << "10 + 100 = " << sum(10, 100) << std::endl;

  auto now = std::chrono::steady_clock::now();
  auto r = sum(100, 10);
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Computed 100 + 10 = " << r << std::endl;
  std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
}
