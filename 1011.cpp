#include<iostream>
#include<math.h>
using namespace std;

void testcase(){
    long k, n;

    long dem;
    long temp = 0;
    long i = 1;

    cin >> k;
    cin >> n;

    dem = n - k;

    while(dem > 0){
        dem = dem - ceil(i/2.0f);
        i = i + 1;
    }
    
    cout << i-1 << endl;
}

int main(){

    int t;

    cin >> t;

    for(int i=0; i<t; i++){
        testcase();
    }

    return 0;
}