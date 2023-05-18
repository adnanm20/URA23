#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>

void toLower(std::string& s) {
  for(int i = 0; i < s.size(); ++i)
    s[i] = tolower(s[i]);
}

void removeDuplicates(std::vector<std::string>& s) {
  auto it1 = s.begin(), it2 = s.begin();
  while(++it2 != s.end()) {
    if(*it1 != *it2 && ++it1 != it2) {
      *it1 = *it2;
    }
  }
  s.erase(++it1, s.end());
}

template<typename It, typename T>
bool find(It begin, It end, T& val) {
  if(begin == end) return 0;
  if(end - begin == 1) return *begin == val;

  It mid = begin + (end - begin) / 2;
  if(*mid < val) {
    begin = mid + 1;
  } else {
    end = mid;
  }
  return find(begin, end, val);
}

int main(void)
{
  std::vector<std::string> s;
  std::string w;
  std::ifstream in("shakespeare.txt");
  while(!in.eof()) {
    in >> w;
    toLower(w);
    s.push_back(w);
  }
  std::sort(s.begin(), s.end());
  removeDuplicates(s);
  std::cout << "Search among " << s.size() << " words." << std::endl;
  bool found = false;
  std::cout << "Search word: ";
  while(std::cin >> w) {
    auto now = std::chrono::system_clock::now();
    toLower(w);
    found = find(s.begin(), s.end(), w);
    auto elapsed = std::chrono::system_clock::now() - now;
    std::cout << "Rijec " << (found ? "" : "ne ") << "postoji!" << std::endl;
    std::cout << "Search time: " << elapsed.count()/1000 << "ms" << std::endl;
    std::cout << "Search word: ";
  }
  
  return 0;
}
