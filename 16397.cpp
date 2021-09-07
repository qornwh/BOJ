#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#define MAX 100000

using namespace std;

char a = 'a';
char b = 'b';

int N = 0;
int T = 0;
int G = 0;
int result = 0;
string ANG = "ANG";
queue<pair<int, int>> q;

int visit[MAX];

int B(int);

void bfs() {
  visit[N] = 1;
  q.push({N, 0});
  while(!q.empty()) {
    int value = q.front().first;
    int idx = q.front().second;
    q.pop();

    if(idx > T) {
      // 인덱스초과
      return;
    }

    if(value == G) {
      // 결과
      result = idx;
      return;
    }


    if (value*2 < MAX) {
      int _value = B(value * 2);
      if (visit[_value] == 0 && _value > -2) {
        visit[_value] = 1; // 너비우선탐색 최단이라서 다음에 같은수가 나타나면 인덱스가 커져서 방문할 필요없다.  이게 됨 깊이우선은 안된다.
        q.push({_value, idx + 1});
      }
    }
    if (value + 1 < MAX) {
      int _value = value + 1;
      if (visit[_value] == 0) {
        visit[_value] = 1;
        q.push({_value, idx + 1});
      }
    }
  }
}

int B(int N2) {

  int temp = N2;
  int _ten = 1;
  while(1) {
    if (temp / 10 == 0)
      break;
    temp /= 10; 
    _ten *= 10;
  }
  N2 -= _ten;

  return N2;
}

int main() {
  cin >> N;
  cin >> T;
  cin >> G;

  if (N == G) {
    cout << result << endl;
    return 0;
  }

  bfs();

  if(result == 0) {
    cout << ANG << endl;
  } else {
    cout << result << endl;
  }

  return 0;
}