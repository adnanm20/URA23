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
void mergesort(It begin, It end, C comp) {
  if(end - begin < 2) return;

  It middle = begin + (end - begin) / 2;
  mergesort(begin, middle, comp);
  mergesort(middle, end, comp);
  merge(begin, middle, end, comp);
} //O(nlogn) random access iterator inplace stabilan

template<typename It, typename C>
void merge(It first, It second, It end, C comp) {
  std::vector<typename It::value_type> v;
  It start = first, mid = second;
  while(first != mid) {
    if(second != end && comp(*second, *first)) {
      v.push_back(std::move(*second++));
    } else
      v.push_back(std::move(*first++));
  }
  for(auto i = v.begin(); i != v.end(); ++i)
    *start++ = std::move(*i);
}

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
    mergesort(v.begin(), v.end(), [](int a, int b) {return a < b;});
    auto elapsed = std::chrono::system_clock::now() - now;
    avg += elapsed.count()/1000;
    // std::cout << std::is_sorted(v.begin(), v.end()) << std::endl;
    std::cout << elapsed.count()/1000 << "us" << std::endl;
  }
  std::cout << "Avg time: " << avg/numOfTests << "us" << std::endl;
  return 0;
}
