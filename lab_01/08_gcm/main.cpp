#include <iostream>
#include <chrono>

// implement a recursive function that computes the gcm of a given number
int gcm(int a, int b) {
  if (a == b) return a;
  if (a > b) return gcm(a-b, b);
  return gcm(a, b - a);
}

int gcm1(int a, int b) {
  if (b == 0) return a;
  return gcm1(b, a % b);
}

int main() {
  std::cout << "Greatest common measure of 4, 4 is: " << gcm1(4, 4) << std::endl;
  std::cout << "Greatest common measure of 120, 5 is: " << gcm1(5, 120) << std::endl;

  auto now = std::chrono::steady_clock::now();
  auto r = gcm1(250, 7);
  auto elapsed = std::chrono::steady_clock::now() - now;
  std::cout << "Greatest common measure of 250, 7 is: " << r << std::endl;
  std::cout << "Elapsed time: " << elapsed.count() << "ns" << std::endl;
}
