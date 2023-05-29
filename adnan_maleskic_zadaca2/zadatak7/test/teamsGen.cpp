#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

//   std::string naziv;
//   int bodovi;
//   int primljeniGolovi;
//   int postignutiGolovi;

std::string getRandString(int len) {
  std::string res = "";
  static std::string chars = "abcdefghijklmnopqrstuvwxyz";
  for(;len > 0; --len) {
    res.push_back(chars[rand() % chars.length()]);
  }
  return res;
}

int main(void)
{
  srand(time(NULL));

  for(int i = 0; i < 20; ++i) {
    std::cout << getRandString(7) << ' ' <<
      rand() % 30 << ' ' << rand() % 12 << ' ' << rand() % 12 << '\n';
  }
  
  return 0;
}
