#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#define N 10
#define CHEET 4;

using namespace std;

int grid[N][N] = {0}; // 원본
int result = -1;
int sheets[6] = {-1, 5, 5, 5, 5, 5}; 

void dfs(int, int, int);
bool fill(int, int, int);
void update(int, int, int);
void downGrade(int, int, int);
bool checkFill();
bool checkFill2(int, int);

void dfs(int x, int y, int count) {

  for (int i = y; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(grid[i][j] == 1) {
        for (int k = 5; k > 0; k--) {
          if(fill(j, i, k) && sheets[k] > 0 && checkFill2(j, i)) {
            // 업데이트 
            // 다시 트래킹
            // 제거
            update(j, i, k);
            //cout << "rrrr ::: " << "y : " << i << " x: " << j << " sheet : " << k;
            //for (int s = 5; s > 0; s--) {
            //  cout << " s[" << s << "]" << " : " << sheets[s];
            //}
            
            //cout << " count : " << count << endl;
            dfs(j + k, i, count+1);
            downGrade(j, i, k);
          }
        }
      }
    }
  }
  //cout << "end : " << count << endl;
  if(checkFill()) {
    if(count < result || result < 0) {
      //cout << "c : " << count << endl;
      //for (int i = 0; i < N; i++) {
      //  for (int j = 0; j < N; j++) {
      //    cout << grid[i][j] << " ";
      //  }
      //  cout << endl;
      //}
      result = count;
    }
  }
}

void update(int x, int y, int cheetSize) {
  for (int i = y; i < y + cheetSize; i++) {
    for (int j = x; j < x + cheetSize; j++) {
      grid[i][j] = -1;
    }
  }

  sheets[cheetSize] = sheets[cheetSize] - 1;
}

void downGrade(int x, int y, int cheetSize) {
  for (int i = y; i < y + cheetSize; i++) {
    for (int j = x; j < x + cheetSize; j++) {
      grid[i][j] = 1;
    }
  }

  sheets[cheetSize] = sheets[cheetSize] + 1;
}

bool checkFill() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if(grid[i][j] == 1) {
        return false;
      }
    }
  }
  return true;
}

bool checkFill2(int x, int y) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == y && j == x) {
        return true;
      }
      if(grid[i][j] == 1) {
        return false;
      }

    }
  }
  return true;
}

bool fill(int x, int y, int cheetSize) {
  if(x+cheetSize-1 < N && y+cheetSize-1 < N) {
    for (int i = y; i < y+cheetSize; i++) {
      for (int j = x; j < x+cheetSize; j++) {
        if(grid[i][j] < 1) {
          return false;
        }
      }
    }
    //if(cheetSize > 2) {
    //  cout << "x : " << x << " y : " << y << " grid : " << grid[y+1][x+1] << endl;
    //    for (int i = 0; i < N; i++) {
    //      for (int j = 0; j < N; j++) {
    //        //cin >> input;
    //        cout << grid[i][j] << " ";
    //      }
    //    cout << endl;
    //  }
    //}
    return true;
  }
  return false;
}

int main() {
  int input = 0;
  int total = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> input;
      grid[i][j] = input;
      if(input == 1)
        total = total + 1;
    }
  }

  if(total == 100) {
    cout << 4;
    return 0;
  } else if (total == 0) {
    cout << 0;
    return 0;
  }
  
  dfs(0, 0, 0);

  cout << result << endl;

  //for (int i = 0; i < N; i++) {
  //  for (int j = 0; j < N; j++) {
  //    //cin >> input;
  //    cout << grid[i][j] << " " ;
  //  }
  //  cout << endl;
  //}

  return 0;
}