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
void insertionsort_var(It begin, It end, C comp, int step) {
  begin += step;
  It start = begin;
  while(begin < end) {
    It temp = begin;
    while(temp >= start && comp(*temp, *(temp-step))) {
      std::swap(*temp, *(temp-step));
      temp -= step;
    }
    ++begin;
  }
}

template<typename It, typename C>
void shellsort(It begin, It end, C comp) {
  int step = (end-begin)/2;
  while(step >= 1) {
    insertionsort_var(begin, end, comp, step);
    step /= 2;
  }
} //O(n^3/2) randomaccess in-place nestabilan

int main(void)
{
  const int arraySize = 5000;
  std::vector<int> v;
  for(int i = 0; i < arraySize; ++i) {
    v.push_back(i);
  }
  unsigned long avg = 0;
  int numOfTests = 100;
  for(int i = 0; i < numOfTests; ++i) {
    std::random_shuffle(v.begin(), v.end());
    std::cout << "Sorting " << i+1 << std::endl;
    auto now = std::chrono::system_clock::now();
    shellsort(v.begin(), v.end(), [](int a, int b) {return a < b;});
    auto elapsed = std::chrono::system_clock::now() - now;
    avg += elapsed.count()/1000;
    // std::cout << std::is_sorted(v.begin(), v.end()) << std::endl;
    std::cout << elapsed.count()/1000 << "us" << std::endl;
  }
  std::cout << "Avg time: " << avg/numOfTests << "us" << std::endl;
  return 0;
}
