#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

void hotel(){
    int h,w,n;
    int cmd =0, gh=0;

    cin >> h >> w >> n;
    for(int i = 1; i<=w; i++){
        for(int j=1; j<=h; j++){
            n--;
            if(n == 0){
                printf("%d%02d\n", j, i);
                return;
            }
        }
    }
}

int main(){
    int num;

    cin >> num;
    for(int i=0; i<num; i++){
        hotel();
    }

    return 0;
}