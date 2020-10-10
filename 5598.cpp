#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main(){

    string str;

    cin >>str;
    int len = str.length();

    for(int i =0; i<len; i++){
        if(str[i] < 68){
            str[i]+=26;
        }
        else if(str[i]<100 && str[i]>96){
            str[i]+=26;
        }
        printf("%c", char(str[i]-3));
    }

    return 0;
}