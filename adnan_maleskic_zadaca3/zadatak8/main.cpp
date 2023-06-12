#include <iostream>
#include <vector>

bool konjic(std::vector<std::vector<int>>& ploca, int posx=0, int posy=0, int jumps = 1) {
  if(posx > ploca[0].size()-1 || posy > ploca.size()-1 || posx < 0 || posy < 0) return false;
  if(ploca[posx][posy] != 0) return false;
  ploca[posx][posy] = jumps;
  if(jumps == ploca.size() * ploca[0].size()) return true;
  if(konjic(ploca, posx+1, posy+2, jumps+1)) return true;
  if(konjic(ploca, posx+1, posy-2, jumps+1)) return true;
  if(konjic(ploca, posx-1, posy+2, jumps+1)) return true;
  if(konjic(ploca, posx-1, posy-2, jumps+1)) return true;
  if(konjic(ploca, posx+2, posy+1, jumps+1)) return true;
  if(konjic(ploca, posx-2, posy+1, jumps+1)) return true;
  if(konjic(ploca, posx+2, posy-1, jumps+1)) return true;
  if(konjic(ploca, posx-2, posy-1, jumps+1)) return true;
  ploca[posx][posy] = 0;
  return false;
}

int main(void)
{
  const int size_ = 6;//radi i za 6 i 7, 8 traje predugo
  std::vector<std::vector<int>> ploca;
  for(int i = 0; i < size_; ++i) {
    std::vector<int> temp;
    for(int j = 0; j < size_; ++j) {
      temp.push_back(0);
    } 
    ploca.push_back(temp);
  }

  if(konjic(ploca, 4, 0) == false) {
    std::cout << "No solution" << std::endl;
    return 0;
  }

  for(int i = 0; i < size_; ++i) {
    for(int j = 0; j < size_; ++j) {
      std::cout << ploca[i][j] << ' ';
    } 
    std::cout << '\n';
  }
  
  return 0;
}
