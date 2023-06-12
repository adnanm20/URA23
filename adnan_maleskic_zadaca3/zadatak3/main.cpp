#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
int lrs(std::vector<T>& nums) {
  std::vector<int> temp(nums.size(), 1);
  int max = 0;

  for(int i = 0; i < nums.size(); ++i)
    for(int j = 0; j < i; ++j)
      if(nums[i] > nums[j] && temp[i] < temp[j]+1) {
        temp[i] = temp[j] + 1;
        if(temp[i] > max) max = temp[i];
      }

  return max;

}

int main(void)
{
  std::vector<int> v{10, 22, 9, 33, 21, 50, 41, 60, 80};
  std::cout << lrs(v) << std::endl;
  
  return 0;
}
