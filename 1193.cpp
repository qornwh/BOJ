#include<iostream>
using namespace std;

int main(){
    int i = 1;
    int x;
    int count = 1;
    double result = 1;

    cin >> x;

    while(x > i){
        x = x - i;
        count = count + 1;
        
        i = i+1;
    }
    //cout <<"ss" << count << endl;
    if(count %2 == 1){
        cout << (count+1-x) <<"/"<< x << endl;
        //result = double(count+1-x)/x; 
        //cout << (count+1-x) << endl;
        //cout << x << endl;
    }
    else if(count %2 == 0){
        cout << x <<"/"<< (count+1-x) << endl;
        //result = x/double(count+1-x); 
        //cout << x << endl;
        //cout << (count+1-x) << endl;
    }
    //cout << result << endl;

    return 0;
}