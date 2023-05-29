#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

template<typename It, typename C>
void insertionsort(It begin, It end, C comp) {
  It start = begin;
  while(begin != end) {
    It temp = begin;
    while(temp != start && comp(*temp, *(temp-1))) {
      std::swap(*temp, *(temp-1));
      --temp;
    }
    ++begin;
  }
}

template<typename It, typename C>
void quicksort(It begin, It end, C comp) {
  if(end - begin < 17) {
    insertionsort(begin, end, comp);
    return;
  }

  It mid = std::partition(begin, end-1, [&end, &comp](typename It::value_type a){return comp(a, *(end-1));});
  std::swap(*mid, *(end-1));

  quicksort(begin, mid, comp);
  quicksort(mid+1, end, comp);
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
    quicksort(v.begin(), v.end(), [](int a, int b) {return a < b;});
    auto elapsed = std::chrono::system_clock::now() - now;
    avg += elapsed.count()/1000;
    // std::cout << std::is_sorted(v.begin(), v.end()) << std::endl;
    std::cout << elapsed.count()/1000 << "us" << std::endl;
  }
  std::cout << "Avg time: " << avg/numOfTests << "us" << std::endl;
  return 0;
}
