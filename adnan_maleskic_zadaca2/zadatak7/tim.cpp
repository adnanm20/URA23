#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Tim {
  std::string naziv;
  int bodovi;
  int primljeniGolovi;
  int postignutiGolovi;
};

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

template<typename It, typename C>
void quicksort(It begin, It end, C comp) {
  if(end - begin < 2) return;

  It mid = std::partition(begin, end-1, [&end, &comp](typename It::value_type a){return comp(a, *(end-1));});
  std::swap(*mid, *(end-1));

  quicksort(begin, mid, comp);
  quicksort(mid+1, end, comp);
}

std::istream& operator>>(std::istream& i, Tim& t) {
  return i >> t.naziv >> t.bodovi >> t.primljeniGolovi >> t.postignutiGolovi;
}

std::ostream& operator<<(std::ostream& o, Tim& t) {
  return o << t.naziv << ' ' << t.bodovi << ' ' << t.primljeniGolovi << ' ' << t.postignutiGolovi;
}

int main(void)
{
  std::vector<Tim> timovi_;

  Tim temp;
  while(std::cin >> temp) {
    timovi_.push_back(temp);
  }

  //brzi metod sortiranja ali nije stabilan, ovaj korak ne zahtijeva stabilnost
  quicksort(timovi_.begin(), timovi_.end(), [](const Tim& a, const Tim& b) {
        return a.naziv < b.naziv;});
  //svaki naredni korak zahtijeva stabilnost, a mergesort je najbrzi dosad nauceni stabilan sort alogritam
  mergesort(timovi_.begin(), timovi_.end(), [](const Tim& a, const Tim& b) {
        return a.postignutiGolovi > b.postignutiGolovi;});
  mergesort(timovi_.begin(), timovi_.end(), [](const Tim& a, const Tim& b) {
        return (a.postignutiGolovi - a.primljeniGolovi) > (b.postignutiGolovi - b.primljeniGolovi);});
  mergesort(timovi_.begin(), timovi_.end(), [](const Tim& a, const Tim& b) {
        return a.bodovi > b.bodovi;});
  //slozenost je O(nlogn) jer sortiranje se vrsi jedno nakon drugog

  for(auto i : timovi_) {
    std::cout << i << '\n';
  }
  
  return 0;
}
