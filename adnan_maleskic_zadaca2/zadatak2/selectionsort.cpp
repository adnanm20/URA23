#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template<typename It>
void print(It begin, It end) {
  while(begin != end)
    std::cout << *begin++ << ' ';
  std::cout << std::endl;
}

template<typename It, typename C>
void selectionsort(It begin, It end, C comp) {
  It smallest = begin;
  It start = begin;
  while(begin != end) {
    smallest = begin;
    It temp = begin+1;
    while(temp != end) {
      if(comp(*temp, *smallest)) {
        smallest = temp;
      }
      ++temp;
    }
    std::swap(*begin, *smallest);
    ++begin;
  }
} //O(n^2) forwardIterator inplace nije stabilan

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
    selectionsort(v.begin(), v.end(), [](int a, int b) {return a < b;});
    auto elapsed = std::chrono::system_clock::now() - now;
    avg += elapsed.count()/1000;
    // std::cout << std::is_sorted(v.begin(), v.end()) << std::endl;
    std::cout << elapsed.count()/1000 << "us" << std::endl;
  }
  std::cout << "Avg time: " << avg/numOfTests << "us" << std::endl;
  return 0;
}
