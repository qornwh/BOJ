#include <iostream>
#include <string>
#include <queue>
#include <set>
#define MAX 10

using namespace std;

int scorers[MAX] = {0}; // 순서대로 주자의 타점
int batters[MAX] = {0}; // 타자가 있는지 확인용 배열열
int inning = 0;

int ru[4] = {0}; // 루수 확인인
set<pair<int, int>> fac;

void dfs(int, int);

void game() {
  // 3아웃되면 이닝 끝 다음이닝으로
  for (int i = 1; i < MAX; i++) {
    dfs(i, 1);
  }
}

void dfs(int runner, int order) {
  bool flag = true;

  for (int b = 1; b < MAX; b++) {
    if(batters[b] != 1) {
      fac.insert({b, order});
      batters[b] = 1;
      dfs(b, order++);
      set<pair<int,int>>::iterator it = fac.find({b, order});
      fac.erase(it);
      batters[b] = 0;
      flag = false;
    }
  }

  if (flag) {
    // 끝까지 다오면 이제 
    // 그냥 여기서 계산하는게 좋을까?
    int score = 0;
    for (int i = 0; i < inning; i++) {
      int out = 0;
      for(auto p : fac) {
        pair<int,int> _p = p;
        if (scorers[_p.first] == 0) {
          out++;
        }
        if (out == 3) {
          out = 0;
          break;
        }
        if (scorers[_p.first] > 0) {
          int sco = scorers[_p.first];

          if (sco == 4) {
            for (int r = 3; r >= 1; r ++) {
              if(ru[r] > 0) {
                ru[r] = 0;
                score++;
              }
            }
          } else {
            for (int r = 3; r >= 1; r ++) {
              if (ru[r]+sco >= 4 && ru[r] > 0){
                score++;
              } else {
                if (ru[r] > 0) {
                  ru[r] = 0;
                  ru[sco + r] = 1;
                }
              }
            }
            ru[sco] = 1;
          }
        }
      }
    }
    cout << "score : " << score << endl;
  }
}

int main() {

  // 줄세우는 가지수를 변수에 저장하면 362880이라는 엄청난 공간이 필요하다. 이건 할수 없다. 그래서 dfs 로 구해야 될듯한데....
  for (int i = 0; i < inning; i++) {
    game();
  }
  return 0;
}