#include <iostream>

int sum(const int* array, int n) {
  if(n == 0) return 0;
  return array[n-1] + sum(array, n-1);
}

int main(void)
{
  const int arr[] = {1, 2, 4, 4, 5};
  std::cout << sum(arr, 5) << std::endl;
  return 0;
}
