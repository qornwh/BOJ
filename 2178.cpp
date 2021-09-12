#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

struct coordinate
{
  int x;
  int y;
};

int N, M;
int **grid;
int result = 0;

map<int, int> visit;

queue<pair<coordinate, int>> q;

void bfs();
bool isVisit(int, int);

bool isVisit(int x, int y) {
  if(visit.count(y * M + x) == 0) {
    visit[y * M + x ] = 1;
    if(grid[y][x] == 1) {
      return false;
    }
  }
  return true;
}

void bfs() {

  coordinate firstCoordi;
  firstCoordi.x = 0;
  firstCoordi.y = 0;
  q.push({firstCoordi, 0});
  isVisit(0, 0);

  while(!q.empty()) {
    coordinate coordi = q.front().first;
    int count = q.front().second;
    q.pop();

    int x = coordi.x;
    int y = coordi.y;
    count += 1;

    if (x+1 == M && y+1 == N) {
      result = count;
      break;
    }

    if (x-1 >= 0 && !isVisit(x-1, y)) {
      coordinate _coordi;
      _coordi.x = x - 1;
      _coordi.y = y;
      q.push({_coordi, count});
    } 
    if (x+1 < M && !isVisit(x+1, y)) {
      coordinate _coordi;
      _coordi.x = x + 1;
      _coordi.y = y;
      q.push({_coordi, count});
    }
    if(y-1 >= 0 && !isVisit(x, y-1)) {
      coordinate _coordi;
      _coordi.x = x;
      _coordi.y = y - 1;
      q.push({_coordi, count});
    }
    if(y+1 < N && !isVisit(x, y+1)) {
      coordinate _coordi;
      _coordi.x = x;
      _coordi.y = y + 1;
      q.push({_coordi, count});
    }
  }
}

int ten(int idx) {
  int _ten = 1;
  for (int i = 1; i < idx; i++) {
    _ten *= 10;
  }
  return _ten;
}

int main() {
  string input = "";
  cin >> N;
  cin >> M;

  grid = new int *[N];
  for (int i = 0; i < N; i++) {
    grid[i] = new int[M];
  }

  for (int n = 0; n < N; n++) {
    cin >> input;
    for (int m = 0; m < M; m++) {
      //int _ten = ten(M - m);
      //grid[n][m] = input / _ten;
      //input = input % _ten;
      // 아 이걸 인트로 한다는 생각을 해버렸네 ㅋ

      grid[n][m] = int(input[m] - '0');
    }
  }

  bfs();

  cout << result << endl;

  for (int i = 0; i < N; i++) {
    delete[] grid[i];
  }
  delete[] grid;

  return 0;
}
