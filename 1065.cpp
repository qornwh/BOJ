#include<iostream>
using namespace std;

int main(){
    int num;
    int count;
    int temp =110;

    cin >> num;

    if(num>110){
        count = 99;
        while(temp < num){
            temp = temp +1;
            int n100, n10, n1;

            n100 = temp / 100;
            n10  = (temp % 100) / 10;
            n1   = (temp % 100) % 10;

            if(n100-n10 == n10-n1){
                count = count +1;
            }
        }
        cout << count << endl;
    }
    else{
        if(num >= 100)
            cout << 99 <<endl;
        else
            cout << num << endl;
    }
    return 0;
}