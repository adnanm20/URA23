#include <iostream>

//cemu memoizacija???
int collatz(unsigned long n) {
  if(n == 1) return 0;
  return 1 + collatz((n%2 ? 3*n+1 : n/2));
}

int main(void)
{
  std::cout << collatz(989345275647) << std::endl;
  
  return 0;
}
