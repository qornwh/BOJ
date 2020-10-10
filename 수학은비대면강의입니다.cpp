#include <iostream>
#include <list>
#include <cstring>
using namespace std;

int main(){
    double a,b,c,d,e,f;
    int x =0 , y= 0;
    cin >>a >>b>>c>>d>>e>>f;

    if(c == 0 && f == 0){
        cout << 0 <<" "<<0<<endl;
        return 0;
    }
    if(b == 0){
        if(d == 0){
            x = c/a;
            y = f/e;
            cout << x <<" "<< y << endl;
            return 0;
        }
        x = c/a;
        y = -(d*x - f)/e;
        cout << x <<" "<< y << endl;
        return 0;
    }
    if(e == 0){
        if(a == 0){
            x = f/d;
            y = c/b;
            cout << x <<" "<< y << endl;
            return 0;
        }
        x = f/d;
        y = -(a*x - c)/b;
        cout << x <<" "<< y << endl;
        return 0;
    }
    if(a == 0){
        if(e == 0){
            x = c/b;
            y = f/d;
            cout << x <<" "<< y << endl;
            return 0;
        }
        y = c/b;
        x = -(e*y - f)/d;
        cout << x <<" "<< y << endl;
        return 0;
    }
    if(d == 0){
        if(a == 0){
            x = f/d;
            y = c/b;
            cout << x <<" "<< y << endl;
            return 0;
        }
        y = f/d;
        x = -(b*y - c)/a;
        cout << x <<" "<< y << endl;
        return 0;
    }

    for(int i = -999; i < 1000; i++)
    {
        double  y1 = a*i - c;
        double  y2 = d*i - f;

        if(y1/b == y2/e){
            x = i;
            y = (-1)*y2/e;
            break;
        }
    }

    cout << x <<" "<< y << endl;
    return 0;
}