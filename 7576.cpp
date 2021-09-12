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
};

int N = 0;
int M = 0;

int **grid;
int result;
int total;
int date = 0;

vector<coordinate> temp;
bool findTemp(vector<coordinate>, int, int);

bool findTemp(vector<coordinate> _temp, int x, int y) {
  int size = _temp.size();

  if(size > 0) {
    for (int i = 0; i < size; i++) {
      coordinate codi = _temp.at(i);

      if(x == codi.x && y == codi.y) {
        return true;
      } 
    }
  }
  return false;
}

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
      temp.pop_back();

      //cout << "x : " << x << " y : " << y << endl;
      if(x-1 >= 0 && grid[y][x-1] == 0) {
        coordinate _c;
        _c.x = x - 1;
        _c.y = y;
        _temp.push_back(_c);
        grid[y][x - 1] = 1;
      }
      if(x+1 < M && grid[y][x+1] == 0) {
        coordinate _c;
        _c.x = x + 1;
        _c.y = y;
        _temp.push_back(_c);
        grid[y][x + 1] = 1;
      }
      if(y-1 >= 0 && grid[y-1][x] == 0) {
        coordinate _c;
        _c.x = x;
        _c.y = y-1;
        _temp.push_back(_c);
        grid[y-1][x] = 1;
      }
      if(y+1 < N && grid[y+1][x] == 0) {
        coordinate _c;
        _c.x = x;
        _c.y = y+1;
        _temp.push_back(_c);
        grid[y+1][x] = 1;
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

  int input = -1;
  
  total = N * M;
  grid = new int*[N];
  for (int n = 0; n < N; n++) {
    grid[n] = new int[M];
  }

  for (int n = 0; n < N; n++) {
    for (int m = 0; m < M; m++) {
      cin >> input;
      grid[n][m] = input;
      if(input == 1) {
        coordinate coordi;
        coordi.x = m;
        coordi.y = n;
        temp.push_back(coordi);
      }
      if(input == -1) {
        total -= 1;
      }
    }
  }
  tomato();

  cout << date << endl;

  return 0;
}