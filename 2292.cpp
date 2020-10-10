#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long num;
    int i = 0;
    int count = 1;
    int sum = 0;

    cin >> num;

    while(num > 1){
        i = i+1;
        sum = i*6;
        num = num - sum;
        count = count + 1;
    }
    cout << count <<endl;

    return 0;
}