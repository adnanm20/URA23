#include <iostream>
#include <vector>

void printThrows(std::vector<int>& b) {
  for(auto i : b) {
    std::cout << i << ' ';
  }
  // std::cout << std::endl;
}

void kockice(int n, int S, int c = 0, std::vector<int> bacanja = std::vector<int>{}) {
  if(c >= S) return;
  if(n == 0) {
    printThrows(bacanja);
    std::cout << "sum=" << c << std::endl;
    return;
  }

  for(int i = 1; i < 7; ++i) {
    bacanja.push_back(i);
    kockice(n-1, S, c+i, bacanja);
    bacanja.pop_back();
  }
}

int main(void)
{
  kockice(5, 15);
  
  return 0;
}
