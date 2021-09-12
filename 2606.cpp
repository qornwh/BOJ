#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;


int compN;
int pairN;
int result = 0;

vector<pair<int, int>> pairs;
queue<pair<int, int>> q;
int *visit;

vector<int> findLink(int);

vector<int> findLink(int number) {
  vector<int> computers;

  vector<pair<int, int>>::iterator iter;
  for(iter = pairs.begin(); iter != pairs.end(); iter++) {
    if (iter->first == number && visit[iter->second - 1] == 0) {
      computers.push_back(iter->second);
    } 
    else if (iter->second == number && visit[iter->first - 1] == 0) {
      computers.push_back(iter->first);
    }
  }

  return computers;
}

void bfs() {
  q.push({1, 0});

  while(!q.empty()) {
    int computerNumber = q.front().first;
    int count = q.front().second;
    visit[computerNumber - 1] = 1;

    q.pop();

    //컴퓨터와 연결된거 모두 찾기
    vector<int> list = findLink(computerNumber);
    if (list.size() > 0) {
      for (int i = 0; i < list.size(); i++) {
        q.push({list.at(i), count});
      }
    }
  }

  for (int i = 1; i < compN; i++) {
    if(visit[i] == 1) {
      result += 1;
    }
  }
}

int main() {
  cin >> compN >> pairN;
  int a;
  int b;

  visit = new int[compN];
  for (int i = 0; i < pairN; i++) {
    cin >> a >> b;

    pairs.push_back({a, b});
  }
  for (int i = 0; i < compN; i++)
    visit[i] = 0;

  bfs();

  cout << result;
  delete[] visit;

  return 0;
}