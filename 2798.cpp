#include<iostream>
using namespace std;

int blackJ(int num[], int m, int size){

    int temp;

    int count = 0;
    int sum = 0;
    int result = 0;

    for(int i = count; i < size-2; i++){
        for(int j = i+1; j < size-1; j++){
            for(int k = j+1; k <size; k++){
                sum = num[i]+num[j]+num[k];
                if(result < sum && sum <= m){
                    result = sum;
                }
                sum = 0;
            }
        }
        count++;
    }
    
    return result;

}

int main(){

    int n, m;
    int sum;
    cin >> n;
    cin >> m;
    int num[n];

    for(int i=0;i<n;i++){
        cin >> num[i];
    }

    sum = blackJ(num, m, n);
    cout << sum << endl;

    return 0;
}