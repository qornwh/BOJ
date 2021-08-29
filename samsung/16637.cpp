#include <iostream>
#include <deque>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N; // 길이
int brcketSize; // 최대 괄호 갯수 
std::string input; // 입력 수식
vector<int> numbers; // 숫자 배열
vector<char> operations; // 사칙연산 기호
int answer = -2147483648; // 최저값

vector<int> cash;


int cal1(int, int, char);

bool find_cash(int idx, vector<int> cash) {
  for (int i = 0; i < cash.size(); i++) {
    if (idx == cash.at(i)) {
      return true;
    }
  }
  return false;
}

void serch(int bck, int stat_bck, int idx) {
  int flag = 0;
  if (idx +1 != numbers.size()){
    flag = 1;
    cash.push_back(idx);
  }

  //cout << "starbck " << stat_bck << " bck " << bck  << " idx " << idx << endl;

  {
    // 계산
    int _result = numbers.at(0);
    //cout << _result << " ";
    
    for (int i = 0; i < numbers.size() - 1; i++) {
      int nextValue = 0;
      bool it = find_cash(i + 1, cash);
      
      if (it){
        nextValue = cal1(numbers.at(i + 1), numbers.at(i + 2), operations.at(i + 1));
        _result = cal1(_result, nextValue, operations.at(i));
        //cout << operations.at(i) << " " << nextValue << " ";
        
        i++;
      } else {
        nextValue = numbers.at(i + 1);
        _result = cal1(_result, nextValue, operations.at(i));
        //cout << operations.at(i) << " " << nextValue << " ";
      }
    }

    answer = max(_result, (int)answer);
    
    //cout << "= " << _result << endl;
  }
  
  if(flag == 1)
    cash.pop_back();
  // 현재 괄호 인덱스 변경
  if (idx+1 < numbers.size()) {
    serch(bck, stat_bck, idx+1);
  }

  // 안쪽으로 더 많은 괄호
  for (int j = idx + 2; j < numbers.size(); j++) {
    cash.push_back(idx);
    serch(bck, stat_bck + 1, j);
    cash.pop_back();
  }

}

int cal1(int  f, int  b, char alt) {
  if (alt == '*') {
    return f * b;
  } else if (alt == '-') {
    return f - b;
  } else {
    return f + b;
  }
}

// 일단 1개씩 배열에 넣기

// ex) 3 - 4 + 8 - 1
// ex) 5 + (4  1)
// ex) 1*2+3*4*5-6*7*8*9*9

void parseMath() {
  for (int i = 0; i < N; i++){
    if (i%2 == 0) {
      numbers.push_back(input.at(i) - '0');
    } else {
      operations.push_back(input.at(i));
    }
  }
  brcketSize = int(operations.size() / 2);
}

int main() {
  cin >> N;
  cin >> input;

  if(N == 1){
    cout << stoi(input) << endl;
    return 0;
  }
  parseMath();
  serch(brcketSize, 1, 1);

  cout << answer << endl;
  return 0;
}