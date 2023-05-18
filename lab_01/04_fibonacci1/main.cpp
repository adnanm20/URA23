#include <chrono>
#include <iostream>

// implement a recursive function that computes the n-th fibonacci number
int fibonacci(int n) {
  if(n < 2) return n;
  return fibonacci(n - 1) + fibonacci(n - 2);
}

// Ova reukrzija se izvrsava u vidu stabla
//                      fib(4)
//                    /       \
//               fib(3)        fib(2)
//              /      \      /      \
//         fib(2)    fib(1)   1        1
//          /   \         \
//         1     1         1


// implement a iterative fibonacci and measure its performance
unsigned long fibonacci_iter(unsigned long n) {
  unsigned long f0 = 0, f1 = 1;
  if(n == 0) return f0;
  for(auto i = 2u; i <= n; ++i) {
    auto temp = f1;
    f1 = f1 + f0;
    f0 = temp;
  }
  return f1;
}

int main() {
  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci(40);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 40 is: " << r << std::endl;
    std::cout << "Elapsed time for recursive method: " << elapsed.count()
              << "ns" << std::endl;
  }
  {
    auto now = std::chrono::steady_clock::now();
    auto r = fibonacci_iter(40);
    auto elapsed = std::chrono::steady_clock::now() - now;
    std::cout << "Fibonacci of 40 is: " << r << std::endl;
    std::cout << "Elapsed time for iterative method: " << elapsed.count()
              << "ns" << std::endl;
  }
}
