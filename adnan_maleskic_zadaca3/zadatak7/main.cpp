#include <iostream>
#include <vector>

bool solve(std::vector<std::vector<int>>& map_, int posX = 0, int posY = 0) {
  if(posX == map_[0].size()-1 && posY == map_.size()-1)
    return true;
  if(posX > map_[0].size()-1 || posY > map_.size()-1) return false;
  if(map_[posX][posY] == 1) return false;

  map_[0][0] = 2;

  bool test = solve(map_, posX+1, posY);
  if(test) {
    map_[posX+1][posY] = 2;
    return true;
  }
  test = solve(map_, posX, posY+1);
  if(test) {
    map_[posX][posY+1] = 2;
    return true;
  }

  return false;
}

int main(void)
{
  int n, m, x;
  std::cin >> n >> m;
  std::vector<std::vector<int>> map_;
  for(int i = 0; i < n; ++i) {
    std::vector<int> temp{};
    for(int j = 0; j < m; ++j) {
      std::cin >> x;
      temp.push_back(x);
    }
    map_.push_back(temp);
  }

  solve(map_);

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < m; ++j) {
      std::cout << map_[i][j] << ' ';
    }
    std::cout << '\n';
  }
  
  return 0;
}
