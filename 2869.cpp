#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int b;
    int a;
    int v;
    int count = 1;
    int result;

    cin >> a >> b >> v;

    v = v - a;
    
    count  = count + ceil(double(v)/(a-b));

    cout << count << endl;

    return 0;
}