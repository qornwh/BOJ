#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int A = 1;
int B = 1;
int C = 1;

int a = 1;
int b = 1;
int c = 1;

struct coordinate
{
  int a;
  int b;
  int c;
};

queue<pair<coordinate ,int>> q;

int visit[201][201][201] = {0,};

int result[201] = {-1,};

void checkVisit(coordinate);

void checkVisit(coordinate codi) {
  if(visit[codi.a][codi.b][codi.c] == 0){
    q.push({codi, codi.c});
    visit[codi.a][codi.b][codi.c] = 1;
    //cout << "check : " << codi.a << " " << codi.b << " " << codi.c << endl;
    if(codi.a == 0) {
      result[codi.c] = 1;
    }
  }
}

void bfs() {
  coordinate codi;
  codi.a = 0;
  codi.b = 0;
  codi.c = C;
  visit[codi.a][codi.b][codi.c] = 1;
  result[codi.c] = 1;
  q.push({codi, C});

  while(!q.empty()) {

    coordinate _codi = q.front().first;
    int a = _codi.a;
    int b = _codi.b;
    int c = _codi.c;

    int Cvalue = q.front().second;

    q.pop();

    if(a != 0) {
      //a -> b
      if(b != B) {
        coordinate _codi2;
        _codi2.c = c;
        if(a+b >= B) {
          _codi2.a = a + b - B;
          _codi2.b = B;
        } else {
          _codi2.a = 0;
          _codi2.b = a + b;
        }
        checkVisit(_codi2);
      } 
      //a -> c 
      if(c != C) {
        coordinate _codi2;
        _codi2.b = b;
        if(a+c >= C) {
          _codi2.a = a + c - C;
          _codi2.c = C;
        } else {
          _codi2.a = 0;
          _codi2.c = a + c;
        }
        checkVisit(_codi2);
      }

    }
    if(b != 0) {
      //b -> a
      if(a != A) {
        coordinate _codi2;
        _codi2.c = c;
        if(b+a >= A) {
          _codi2.b = b + a - A;
          _codi2.a = A;
        } else {
          _codi2.b = 0;
          _codi2.a = b + a;
        }
        checkVisit(_codi2);
      } 
      //b -> c 
      if(c != C) {
        coordinate _codi2;
        _codi2.a = a;
        if(b+c >= C) {
          _codi2.b = b + c - C;
          _codi2.c = C;
        } else {
          _codi2.b = 0;
          _codi2.c = b + c;
        }
        checkVisit(_codi2);
      }
    }
    if(c != 0) {
      //c -> a
      if(a != A) {
        coordinate _codi2;
        _codi2.b = b;
        if(a+c >= A) {
          _codi2.c = a + c - A;
          _codi2.a = A;
        } else {
          _codi2.c = 0;
          _codi2.a = a + c;
        }
        checkVisit(_codi2);
      } 
      //c -> b 
      if(b != B) {
        coordinate _codi2;
        _codi2.a = a;
        if(b+c >= B) {
          _codi2.c = c + b - B;
          _codi2.b = B;
        } else {
          _codi2.c = 0;
          _codi2.b = b + c;
        }
        checkVisit(_codi2);
      }
    }

    //cout << "q size : " << q.size() << endl;
  }
}


int main() {
  cin >> A >> B >> C;
  a = 0;
  b = 0;
  c = C;

  bfs();

  //cout << "result : " << endl;
  for (int i = 0; i < 201; i++) {
    if(result[i] > 0) {
      cout << i << " ";
    }
  }

  return 0;
}