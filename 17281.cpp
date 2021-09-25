#include <iostream>
#include <string>
#include <queue>
#include <set>
#define MAX 9

using namespace std;

int scorers[MAX] = {0}; // 순서대로 주자의 타점
int batters[MAX] = {0}; // 타자가 있는지 확인용 배열열
int inning = 0;

int **grid;

int ru[4] = {0}; // 루수 확인인
vector<int> vec;
int score = 0;

int testt = 0;

void dfs(int, int);

void game() {
  batters[0] = 1;
  for (int i = 1; i < MAX; i++) {
    vec.push_back(i);
    batters[i] = 1;
    dfs(i, 1);
    vec.pop_back();
    batters[i] = 0;
  }
}

void dfs(int runner, int order) {
  bool flag = true;

  for (int b = 1; b < MAX; b++) {
    if(batters[b] != 1) {
      vec.push_back(b);
      batters[b] = 1;
      dfs(b, order++);
      vec.pop_back();
      batters[b] = 0;
      flag = false;
    }
  }

  if (flag) {
    // 끝까지 다오면 이제 
    // 그냥 여기서 계산하는게 좋을까?
    // startp = 0초기화
    int _score = 0;
    int startP = 0;

    vec.insert(vec.begin() + 3, 0);

    // 순서 테스트 
    //for (int i = 0; i < MAX; i++) {
    //  cout << vec[i] << " ";
    //}
    //cout << endl;

    for (int i = 0; i < inning; i++) {      
      int out = 0;
      copy(&grid[i][0], &grid[i][0]+MAX, scorers);

      while (true) {
        int sco = scorers[vec.at(startP)];
        //아웃 1 카운트 증가
        if (sco == 0) {
          out++;
          //3아웃 다음 이닝 ㄱ
          if (out == 3) {
            out = 0;
            // 전주자 초기화
            for (int r = 3; r >= 1; r--) {
              ru[r] = 0;
            }
            // 다음 타자
            if(startP < MAX - 1) {
              startP++;
            } else {
              startP = 0;
            }
            break;
          }
        } else {
          // 점수 있을때
          if (sco == 4) {
            _score++;
            for (int r = 3; r >= 1; r--) {
              if(ru[r] > 0) {
                ru[r] = 0;
                _score++;
              }
            }
          } else {
            for (int r = 3; r >= 1; r--) {
              if (r + sco >= 4 && ru[r] > 0){
                _score++;
                ru[r] = 0;
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
        // 다음 타자
        if(startP < MAX - 1) {
          startP++;
        } else {
          startP = 0;
        }
      }
    }
    if(_score > score) {
      score = _score;
    }
    
    vec.erase(vec.begin() + 3);
  }
}

void setMemory() {
  grid = new int*[inning];
  for (int i = 0; i < inning; i++) {
    grid[i] = new int[MAX];
  }
}

void closeMemoty() {
  for (int i = 0; i < inning; i++) {
    delete[] grid[i];
  }
  delete[] grid;
}

int main() {
  int input = 0;
  cin >> inning;
  setMemory();

  for (int i = 0; i < inning; i++) {
    for (int j = 0; j < MAX; j++) {
      cin >> input;
      grid[i][j] = input;
    }
  }

  // 줄세우는 가지수를 변수에 저장하면 362880이라는 엄청난 공간이 필요하다. 이건 할수 없다. 그래서 dfs 로 구해야 될듯한데....
  game();
  closeMemoty();
  cout << score << endl;
  return 0;
}