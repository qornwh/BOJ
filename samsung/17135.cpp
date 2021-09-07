#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N = 0; // y
int M = 0; // x
int D = 0; // 공격 길이
int **MastGrid;
int **grid; //N*M격자판
int input = 0; // 인풋
int arrowers = 3; // 궁수 명수

int *arrows;
vector<vector<int>> cArrow;
int total = 0;
int enemies = 0;

struct AttckGrid
{
  int x;
  int y;
};

void combination(int, int);
void attack(int);
void loop(int);
bool checkGrid();
void updateGrid(vector<AttckGrid>&);

void memorySet() {
  MastGrid = new int*[N];
  grid = new int *[N];
  for (int i = 0; i < N; i++) {
    MastGrid[i] = new int[M];
    grid[i] = new int[M];
  }
  arrows = new int[arrowers];
}

void memoryDel() {
  for(int i = 0; i < N; ++i) { 
    delete [] MastGrid[i];
    delete[] grid[i];
  }
  delete[] grid; 
  delete [] MastGrid;
  delete arrows;
}

void combination(int n, int r) {

  if (r == arrowers) {
    vector<int> _arrows;
    for (int i = 0; i < 3; i++) {
      _arrows.push_back(arrows[i]);
    }
    cArrow.push_back(_arrows);
  } else if (n > M - 1) {
    return;
  } else {
    arrows[r] = n + 1;
    combination(n + 1, r + 1);
    combination(n + 1, r);
  }
}

void loop(int idx) {

  // 적 존재 유무 확인, 루프 종료
  // 적 공격, 공격가능 좌표 검색
  // 공격후 좌표 업데이트
  // 적 전진
  
  enemies = 0;
  while(1) {
    attack(idx);
    if(!checkGrid()){
      break;
    }
  }
  
  if (total < enemies) {
    total = enemies;
  }

}

void attack(int idx) {
  vector<AttckGrid> vector_ag;
  for (int i = 0; i < arrowers; i ++) {

    int arrowerX = cArrow[idx][i] - 1;

    if (D == 1)
    {
      if (grid[N - 1][arrowerX] == 1) {
        AttckGrid ag;
        ag.x = arrowerX;
        ag.y = N - 1;

        vector_ag.push_back(ag);
      }
    } else {
      bool isShoot = false;
      for (int d = 1; d < D + 1; d++) {

        //좌측
        if(d > 1 && !isShoot) {
          for (int j = 1; j < d; j++) {
            if (arrowerX-(d-j) >= 0 && arrowerX-(d-j) < M) {
              if (N-j >= 0) {
                if (grid[N-j][arrowerX-(d-j)] == 1) {
                  AttckGrid ag;
                  ag.x = arrowerX-(d-j);
                  ag.y = N-j;

                  vector_ag.push_back(ag);
                  isShoot = true;
                  break;
                }
              }
            }
          }
        }
      
        //중간
        if(N-d >=0 && N-d < N) {
          if (grid[N-d][arrowerX] == 1 && !isShoot) {
            AttckGrid ag;
            ag.x = arrowerX;
            ag.y = N-d;

            vector_ag.push_back(ag);
            isShoot = true;
            break;
          }
        }

        //우측
        if(d > 1 && !isShoot) {
          for (int j = d-1; j > 0; j--) {
            if (arrowerX+(d-j) >= 0 && arrowerX+(d-j) < M) {
              if (N-j >= 0) {
                if (grid[N-j][arrowerX+(d-j)] == 1) {
                  AttckGrid ag;
                  ag.x = arrowerX+(d-j);
                  ag.y = N-j;

                  vector_ag.push_back(ag);
                  isShoot = true;
                  break;
                }
              }
            }
          }
        }

        if(isShoot)
          break;
      }       
    }
  }
  updateGrid(vector_ag);
}

void updateGrid(vector<AttckGrid> &vector_ag) {
  if (vector_ag.size() > 0) {
    for (int i = 0; i < vector_ag.size(); i++) {
      AttckGrid ag = vector_ag.at(i);
      if (grid[ag.y][ag.x] == 1){
        grid[ag.y][ag.x] = 0;
        enemies = enemies+1;
      }
    }
  }
}

bool checkGrid() {
  bool isCheck = false;
  for (int j = 0; j < M; j++) {
    grid[N - 1][j] = 0;
  }

  if (N > 1) {
    for (int i = N - 2; i >= 0; i--) {
      for (int j = 0; j < M; j++) {
        if(grid[i][j] == 1) {
          grid[i + 1][j] = 1;
          grid[i][j] = 0;
          isCheck = true;
        }
      }
    }
  }
  return isCheck;
}

bool firstCheck() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (MastGrid[i][j] == 1)
        return true;
    }
  }
  return false;
}

int main() { 
  cin >> N;
  cin >> M;
  cin >> D;

  memorySet();
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> input;
      MastGrid[y][x] = input;
    }
  }

  combination(0,0);
  if(firstCheck()) {
    for (int i = 0; i < cArrow.size(); i++) {
      for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
          grid[y][x] = MastGrid[y][x];
        }
      }
      loop(i);
    }
  }
  
  cout << total << endl;
  memoryDel();
  return 0;
}
