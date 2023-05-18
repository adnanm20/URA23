#include <iostream>
#include <vector>

bool push_unique(std::vector<int>& v, int el) {
  for(auto it = v.begin(); it != v.end(); ++it) {
    if(*it == el) return false;
  }
  v.push_back(el);
  return true;
}

int main(void)
{
  std::vector<int> v = {1, 2, 3, 4};
  int n = 9;
  while(n != 9999) {
    std::cin >> n;
    std::cout << push_unique(v, n) << std::endl;
  }
  
  return 0;
}
