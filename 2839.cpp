#include<iostream>
using namespace std;

int main(){

    int K5 = 5;
    int K3 = 3;

    int N = 0;

    int i = 0;

    cin >> N;

    while(true){
        if(N % 5 == 0){
            cout << N/5+i <<endl;
            break;
        }
        else{
            i = i +1;
            N = N -3;
        }
        if(N<0){
            cout << -1 <<endl;
            break;
        }
    }

    return 0;
}