#include <iostream>
#include <string>

template<typename It>
int lcs(It begin1, It end1, It begin2, It end2) {
  if(begin1 == end1 || begin2 == end2) return 0;
  if(*end1 == *end2) {
    return 1 + lcs(begin1, end1-1, begin2, end2-1);
  }

  return std::max(lcs(begin1, end1-1, begin2, end2), lcs(begin1, end1, begin2, end2-1));
}


void longest_palindromic_sub(std::string s) {
  std::string t = s;
  for(int i = 0; i < t.length()/2; ++i)
    std::swap(t[i], t[t.size()-i-1]);

  std::cout << lcs(t.begin()-1, t.end()-1, s.begin()-1, s.end()-1) << std::endl;


}

int main(void)
{
  longest_palindromic_sub("geeksforgeeks");
  
  return 0;
}
