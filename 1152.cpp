#include <iostream>
#include <cstring>
using namespace std;

int main(){

    string str;
    char tick = false;
    int counter = 0;
    int len;

    getline(cin, str);

    len = str.length();

    for(int i=0; i<len; i++){
        if(str.at(i) != ' '){
            if(!tick){
                counter++;
                tick = true;
            }
        }
        else if(str.at(i) == ' '){
            if(tick){
                tick = false;
            }
        }
    }
    cout << counter;

    return 0;
}