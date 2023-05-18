#include <iostream>
#include <chrono>

// implement a recursive function that computes the product of two
// numbers using the "Egyptian multiplication" method

// O(n) multiply, slow
int multiply(int n, int a) {
  if (n == 1) return a;
  return a + multiply(n - 1, a);
}

// fast_multiply, O(log(n))
bool odd(int n) {
  return n & 1;
}

int half(int n) {
  return n >> 1;
}

int fast_multiply(int n, int a) {
  if(a == 1) return n;

  auto r = fast_multiply(n << 1, a >> 1);
  if(a & 1) r += n;

  return r;
}

int main() {
  std::cout << "multiply 5 * 5 is: " << fast_multiply(5, 5) << std::endl;
  std::cout << "multiply 5 * 11 is: " << fast_multiply(5, 11) << std::endl;

  {
    auto now = std::chrono::steady_clock::now();
    auto r = multiply(1000, 55);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Computed multiply(100, 55) = " << r << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
  }

  {
    auto now = std::chrono::steady_clock::now();
    auto r = fast_multiply(1000, 55);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Computed multiply(100, 55) = " << r << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
  }
}
