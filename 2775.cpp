#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;


int retest(int k, int n){
    int result = 0;
    if(k == 0){
        return n;
    }
    else{
        for(int i=1; i<=n; i++){
            result = result + retest(k-1, i);
        }
        return result;
    }
}

void testcase(){
    int k, n;
    int result = 0;

    cin >> k;
    cin >> n;

    for(int i=1; i<=n; i++){
        result = result + retest(k-1, i);
    }
    
    cout << result << endl;
}

int main(){

    int t;

    cin >> t;

    for(int i=0; i<t; i++){
        testcase();
    }

    return 0;
}