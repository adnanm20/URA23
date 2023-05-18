#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>

template<typename It, typename T>
It upper_bound(It begin, It end, T& el) {
  if(begin == end) return begin;
  if(end - begin < 3)
    return begin+1;

  It mid = begin + (end - begin) / 2;
  if(*mid > el) {
    end = mid;
  } else {
    begin = mid + 1;
  }
  return upper_bound(begin, end, el);
}

int main(void)
{
  std::vector<std::string> s;
  std::string w;
  std::ifstream in("shakespeare.txt");
  auto now = std::chrono::system_clock::now();
  while(!in.eof()) { //O(n)
    in >> w;
    auto it = upper_bound(s.begin(), s.end(), w); //O(logn)
    s.insert(it, w); //O(n)
  } //O(n^2)
  auto elapsed = std::chrono::system_clock::now() - now;
  std::cout << elapsed.count()/1000 << "ms" << std::endl;
  
  return 0;
}
