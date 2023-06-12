#include <iostream>
#include <vector>

void largest_consecutive_sum(std::vector<int>& v) {
  int min = 0, max = 0;
  std::vector<int> temp(v.size(), 0);
  temp[0] = v[0];
  for(int i = 1; i < v.size(); ++i) {
    temp[i] = temp[0] + v[i];
    if(v[i] < v[min]) min = i;
    else if(v[i] > v[max]) max = i;
  }


  int sum = 0;
  for(int i = min+1; i <= max; ++i) {
    sum += v[i];
    std::cout << v[i] << ' ';
  }
  std::cout << std::endl << sum << std::endl;

}

int main(void)
{
  std::vector<int> v{-2, -3, 4, -1, -2, 1, 5, -3};
  largest_consecutive_sum(v);
  
  return 0;
}
