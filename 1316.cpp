#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main1316(){

    int num;
    list<string> l;
    string str;
    int count = 0;
    bool check = false;

    cin >> num;

    for(int i=0; i<num; i++){
        str = "";
        cin >> str;    
        l.push_back(str);       
    }
    
    for(int i=0; i<num; i++){
        str = l.front();
        l.pop_front();
        int len = str.length();
        string temp;
        check = true;
        for(int j=0; j<len; j++){
            temp += str[j];

            int k = temp.find(str[j]);
            if(k <= 100 && k != j){
                if(j>0 && str[j] != str[j-1]){
                    check = false;
                    break;
                }
            }
        }
        if(check)
            count++;
    }

    cout << count;

    return 0;
}