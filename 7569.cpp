#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct coordinate
{
  int x;
  int y;
  int h;
};

int N = 0;
int M = 0;
int H = 0;

int ***grid;
int result;
int total;
int date = 0;

vector<coordinate> temp;

void tomato() {
  int size = temp.size();
  result += size;

  while(1) {
    vector<coordinate> _temp; // 이번에 추가될 좌표
    date += 1;
    for (int i = size - 1; i >= 0; i--) {
      coordinate c = temp.at(i);

      int x = c.x;
      int y = c.y;
      int h = c.h;
      temp.pop_back();

      //cout << "x : " << x << " y : " << y << " h :" << h << endl;
      if(x-1 >= 0 && grid[h][y][x-1] == 0) {
        coordinate _c;
        _c.x = x - 1;
        _c.y = y;
        _c.h = h;
        _temp.push_back(_c);
        grid[h][y][x - 1] = 1;
      }
      if(x+1 < M && grid[h][y][x+1] == 0) {
        coordinate _c;
        _c.x = x + 1;
        _c.y = y;
        _c.h = h;
        _temp.push_back(_c);
        grid[h][y][x + 1] = 1;
      }
      if(y-1 >= 0 && grid[h][y-1][x] == 0) {
        coordinate _c;
        _c.x = x;
        _c.y = y-1;
        _c.h = h;
        _temp.push_back(_c);
        grid[h][y-1][x] = 1;
      }
      if(y+1 < N && grid[h][y+1][x] == 0) {
        coordinate _c;
        _c.x = x;
        _c.y = y+1;
        _c.h = h;
        _temp.push_back(_c);
        grid[h][y+1][x] = 1;
      }
      if(h-1 >= 0 && grid[h-1][y][x] == 0) {
        coordinate _c;
        _c.x = x;
        _c.y = y;
        _c.h = h-1;
        _temp.push_back(_c);
        grid[h-1][y][x] = 1;
      }
      if(h+1 < H && grid[h+1][y][x] == 0) {
        coordinate _c;
        _c.x = x;
        _c.y = y;
        _c.h = h+1;
        _temp.push_back(_c);
        grid[h+1][y][x] = 1;
      }
    }
    size = _temp.size();
    result += size;

    if (result == total) {
      if (date == 1)
        date = 0;
      break;
    }

    if(size == 0) {
      date = -1;
      break;
    }
    //cout << "data : " << date << " result : " << result << endl;

    temp = _temp;
  }
}

int main() { 
  cin >> M;
  cin >> N;
  cin >> H;

  int input = -1;
  
  total = N * M * H;

  grid = new int **[H];
  for (int h = 0; h < H; h++) {
    grid[h] = new int *[N];
    for (int n = 0; n < N; n++) {
      grid[h][n] = new int[M];
    }
  }

  for (int h = 0; h < H; h++) {
    for (int n = 0; n < N; n++)
    {
      for (int m = 0; m < M; m++)
      {
        cin >> input;
        grid[h][n][m] = input;
        if (input == 1)
        {
          coordinate coordi;
          coordi.x = m;
          coordi.y = n;
          coordi.h = h;
          temp.push_back(coordi);
        }
        if (input == -1)
        {
          total -= 1;
        }
      }
    }
  }

  tomato();

  cout << date << endl;

  return 0;
}

//7tl 50