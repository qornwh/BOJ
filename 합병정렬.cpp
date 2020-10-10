#include<iostream>
using namespace std;

void merge(int h, int m, int U[], int V[], int N[]){
    int i,j,k;

    i =0; j = 0; k=0;
    while(i < h && j < m){
        if(U[i] < V[j]){
            N[k] = U[i];
            i++;
        }
        else{
            N[k] = V[j];
            j++;
        }
        k++;
    }
    if(i >= h)
        copy(V+j, V+m, N+k);
    else if(j >= m)
        copy(U+i, U+h, N+k);
}

void mergesort(int n, int N[]){
    if(n > 1){
        const int h = n/2, m = n-h;
        int U[h], V[m];

        copy(N, N+h, U);
        for(int i =0; i<h; i++)
            cout <<U[i]<<" ";
        cout << endl;
        copy(N+h, N+n, V);
        for(int i =0; i<n-(h); i++)
            cout <<V[i]<<" ";
        cout << endl;
        mergesort(h,U);
        mergesort(m,V);

        merge(h, m, U, V, N);
    }
}

int main(){
    int n = 8;
    int N[9] = {2, 8, 4, 55, 98, 12, 11, 1, };

    mergesort(n, N);

    for(int i = 0; i<n; i++)
        cout << N[i] <<" ";

    return 0; 
}