#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long A;
    long B;
    long C;
    int num = -1;
    
    cin >> A >> B >> C;

    if(B>=C){
        cout << num << endl;
    }
    else {
        num = ceil(A / (C-B))+1;
        cout << num << endl;
    }

    return 0;
}
