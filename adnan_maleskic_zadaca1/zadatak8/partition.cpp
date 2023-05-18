#include <iostream>
#include <vector>

template<typename ForwardIter, typename P>
ForwardIter partition(ForwardIter begin, ForwardIter end, const P& p) {
  ForwardIter a = begin;
  while(begin != end){
    if(p(*begin)) {
      std::swap(*begin, *a);
      ++a;
    }
    ++begin;
  }
  return a;
}

int main(void)
{
  std::vector<int> v = {1, 3, 4, 2, 7, 8, 9};
  for(auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;

  partition(v.begin(), v.end(), [](const int& a) {return a%2==0;});

  for(auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;

  std::vector<int> v1{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  for(auto it = v1.begin(); it != v1.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;

  partition(v1.begin(), v1.end(), [](const int& a) {return a%2==0;});

  for(auto it = v1.begin(); it != v1.end(); ++it)
    std::cout << *it << ' ';
  std::cout << std::endl;

  std::vector<int> v2{2, 1, 3, 8, 4, 5, 6, 9, 7};
  auto s = partition(v2.begin(), v2.end(),
  [](const int& e) -> bool { return e < 4; });
  for (auto it = begin(v2); it < s; ++it)
  std::cout << *it << ' ';
  std::cout << '*';
  for (; s < end(v2); ++s)
  std::cout << ' ' << *s;
  std::cout << std::endl;
  
  return 0;
}
