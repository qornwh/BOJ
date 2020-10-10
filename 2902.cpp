#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main(){

    string str;

    cin >>str;
    int len = str.length();

    cout << str[0];
    for(int i =1; i<len; i++){
        if(str[i] == 45){
            cout << str[i+1];
            i++; 
        }
    }

    return 0;
}