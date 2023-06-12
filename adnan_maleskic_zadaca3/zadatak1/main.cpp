#include <iostream>

int rekurzivno(int n) {
  if(n == 0) return 2;
  if(n == 1) return 4;
  if(n == 2) return 12;

  return 3*rekurzivno(n-3) + 2*rekurzivno(n-2) + rekurzivno(n-1);
}

int memoizacijom(int n) {
  static int lookup[100] = {2, 4, 12};
  if(lookup[n] == 0)
    lookup[n] = 3*memoizacijom(n-3) + 2*memoizacijom(n-2) + memoizacijom(n-1);
  return lookup[n];
}

int dinamicki(int n) {
  int lookup[n+1];
  lookup[0] = 2;
  lookup[1] = 4;
  lookup[2] = 12;
  for(int i = 3; i <= n; ++i) {
    lookup[i] = 3*lookup[i-3] + 2*lookup[i-2] + lookup[i-1];
  }

  return lookup[n];
}

int a(int n, int c) {
  if(c == 0)
    return rekurzivno(n);
  if(c==1)
    return memoizacijom(n);
  return dinamicki(n);
}

int main(void)
{
  std::cout << a(5, 0) << ' ' << a(5, 1) << ' ' << a(5, 2) << std::endl;
  
  return 0;
}
