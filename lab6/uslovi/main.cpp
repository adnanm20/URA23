#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Radnik {
  std::string name;
  std::string surname;
  int years;
  int seniority;
  int salary;
  std::string phone;
};

std::istream &operator>>(std::istream &in, Radnik &r) {
  return in >> r.name >> r.surname >> r.years >> r.seniority >> r.salary >>
         r.phone;
}

std::ostream &operator<<(std::ostream &out, const Radnik &r) {
  return out << r.name << ' ' << r.surname << ' ' << r.years << ' '
             << r.seniority << ' ' << r.salary << ' ' << r.phone;
}

int main() {
  Radnik r;
	std::vector<Radnik> radnici;
  while (std::cin >> r) {
    radnici.push_back(r);
  }

  std::sort(radnici.begin(), radnici.end(), 
      [](const Radnik& p, const Radnik& d)
      { return p.years < d.years; }
      );
  std::stable_sort(radnici.begin(), radnici.end(), 
      [](const Radnik& p, const Radnik& d)
      { return p.surname < d.surname; }
      );
  std::stable_sort(radnici.begin(), radnici.end(), 
      [](const Radnik& p, const Radnik& d)
      { return p.name < d.name; }
      );

  for (auto&& r : radnici) {
		std::cout << r << std::endl;
  }
}
