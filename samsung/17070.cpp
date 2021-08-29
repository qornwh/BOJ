#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//깊이우선탐색
int N; // 가로, 세로 길이
int input; // 벽 , 빈공간 입력
int **room; // room 크기 전역변수

int clearNum = 0; // 통과 개수

int startP[4] = {0, 0, 1, 0}; //  y1,x1,y2,x2 

int stateP[4] = {0, 0, 1, 0}; // y1,x1,y2,x2

int checkNextPos(int[]);
int checkStatePos(int[]);

void memorySet() {
  room = new int*[N]; 
  for(int i = 0; i < N; ++i) { 
    room[i] = new int[N];
  }
}

void memoryDel() {
  for(int i = 0; i < N; ++i) { 
    delete [] room[i]; 
  }
  delete[] room;
}

int checkMove(int pos[], int move) {
  int p = checkStatePos(pos);
  int check = 0;
  if (p == 0 && move == 1) {
    return check;
  } else if (p == 1 && move == 0) {
    return check;
  }

  int nextPos[4] = {pos[2], pos[3], pos[2], pos[3]};
  if ( move == 0) {
    nextPos[2] = nextPos[2]+1;
  } else if( move == 1) {
    nextPos[3] = nextPos[3]+1;
  } else {
    nextPos[2] = nextPos[2]+1;
    nextPos[3] = nextPos[3]+1;
  }

  // 여기 들어오면 이동가능
  check = checkNextPos(nextPos);
  if (check == 1) {
    stateP[0] = nextPos[0];
    stateP[1] = nextPos[1];
    stateP[2] = nextPos[2];
    stateP[3] = nextPos[3];
  }

  return check;
}

//벽, 끝 체크
int checkNextPos(int pos[]) {
  int size[2] = {0, 0};

  size[0] = pos[2] - pos[0]; //x 
  size[1] = pos[3] - pos[1]; //y
  
  if (N > pos[2] && N > pos[3]) {
    if (size[0] == 1 && size[1] == 0) {  //x
      if (room[pos[3]][pos[2]] == 0) {
        return 1;
      }
    } else if (size[0] == 0 && size[1] == 1) { //y
      if (room[pos[3]][pos[2]] == 0) {
        return 1;
      }
    } else if (size[0] == 1 && size[1] == 1) { // x y
      if (room[pos[3]][pos[2]] == 0 && room[pos[3]][pos[0]] == 0 && room[pos[1]][pos[2]] == 0) {
        return 1;
      }
    }    
  }
  
  return 0;
}

//사이즈 리턴함수
int checkStatePos(int pos[]) {
  int size[2] = {0, 0};

  size[0] = pos[2] - pos[0]; //x
  size[1] = pos[3] - pos[1]; //y

  if (size[0] == 1 && size[1] == 0) {
    return 0;
  } else if (size[0] == 0 && size[1] == 1) {
    return 1;
  } else if (size[0] == 1 && size[1] == 1) {
    return 2;
  } else {
    system("pause");
    exit(0);
    return -1;
  }
}

void dfs(int pos[]) {
  if (pos[2] == (N - 1) && pos[3] == (N - 1)) {
    clearNum++;
    return;
  }
  
  int state = checkStatePos(pos);

  for (int i = 0; i < 3; i++) {
    if(checkMove(pos, i) == 1) {
        
      //cout <<"idx : " << i  <<" "<< pos[0]<< pos[1]<< pos[2]<< pos[3] << endl;
      int _stateP[4] = {stateP[0], stateP[1], stateP[2], stateP[3]};
      dfs(_stateP);
    }
  }
}

int main() {
  cin >> N;
  memorySet();

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> input;
      room[y][x] = input;
    }
  }

  //cout <<"ffff"<< room[0][2] << endl;

  dfs(startP);
  cout << clearNum << endl;

  memoryDel();

  return 0;
}
