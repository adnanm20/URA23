#include <iostream>

int proizvod(int n) {
  if(n < 2) return n;
  return (n&1 ? 1 : n) * proizvod(n-1);
}


int main(void)
{
  int n;
  std::cout << "Unesite broj n: ";
  std::cin >> n;
  std::cout << proizvod(n) << std::endl;
  return 0;
}
