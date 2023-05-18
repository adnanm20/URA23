#include <iostream>
#include <vector>

template<typename It, typename T>
It upper_bound(It begin, It end, T& el) {
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
  std::vector<int> v = {1, 3, 5, 9, 13, 17, 24};
  for(auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  int el = 25;
  auto it = upper_bound(v.begin(), v.end(), el);
  std::cout << *it << std::endl;
  v.insert(it, el);
  for(auto it = v.begin(); it != v.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
  return 0;
}
