#include <iostream>

bool palindrome(const char* s, int n) {
  if(n < 2) return 1;
  return (s[0] == s[n-1]) && palindrome(++s, n-2);
}

int main(void)
{
  std::cout << palindrome("racecar", 7) << std::endl;
  std::cout << palindrome("racerar", 7) << std::endl;
  std::cout << palindrome("abcddcba", 8) << std::endl;
  std::cout << palindrome("abgddcba", 8) << std::endl;
  
  return 0;
}
