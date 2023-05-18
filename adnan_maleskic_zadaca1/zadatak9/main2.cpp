#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

int main(void)
{
  std::vector<std::string> s;
  std::string w;
  std::ifstream in("shakespeare.txt");
  auto now = std::chrono::system_clock::now();
  while(!in.eof()) { //O(n)
    in >> w;
    s.push_back(w); //O(1)
  }
  std::sort(s.begin(), s.end()); //O(nlogn)
  //O(nlogn)
  auto elapsed = std::chrono::system_clock::now() - now;
  std::cout << elapsed.count()/1000 << "ms" << std::endl;
  
  return 0;
}
