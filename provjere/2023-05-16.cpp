//zadatak1
int suma_cifara(int n) {
  if(n==0) return 0;
  return n%10 + suma_cifara(n/10);
}

//zadatak2
template<typename It, typename P>
It find_last(It begin, It end, P pred) {
  It temp = end--;
  --begin;
  while(end != begin) {
    if(pred(*end)) return end;
    --end;
  }
  return temp;
}

//zadatak3
template<typename It, typename T>
It lower_bound(It begin, It end, T val) {
  if(begin == end) return begin;
  if(end - begin == 1) {
    if(*begin < val) return end;
    return begin;
  }
  It mid = begin + (end - begin) / 2;
  if(*mid < val)
    return lower_bound(mid+1, end, val);
  return lower_bound(begin, mid, val);
}
