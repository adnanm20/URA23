#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template<typename It, typename C>
void bubblesort(It begin, It end, C comp) {
  if(begin == end) return;
  It temp = begin, temp2 = begin;
  while(temp != end) {
    begin = temp2;
    while(begin+1 != end) {
      if(comp(*(begin+1), *begin)) {
        std::swap(*begin, *(begin+1));
      }
      ++begin;
    }
    ++temp;
  }
} //O(n^2) forwardIterator in-place stabilan

int main(void)
{
  const int arraySize = 5000;
  std::vector<int> v;
  for(int i = 0; i < arraySize; ++i) {
    v.push_back(i);
  }
  int avg = 0;
  int numOfTests = 100;
  for(int i = 0; i < numOfTests; ++i) {
    std::random_shuffle(v.begin(), v.end());
    std::cout << "Sorting " << i+1 << std::endl;
    auto now = std::chrono::system_clock::now();
    bubblesort(v.begin(), v.end(), [](int a, int b) {return a < b;});
    auto elapsed = std::chrono::system_clock::now() - now;
    avg += elapsed.count()/1000;
    // std::cout << std::is_sorted(v.begin(), v.end()) << std::endl;
    std::cout << elapsed.count()/1000 << "us" << std::endl;
  }
  std::cout << "Avg time: " << avg/numOfTests << "us" << std::endl;
  return 0;
}
