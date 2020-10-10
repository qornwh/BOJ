#include <iostream>
#include <Vector>

#define MAX 5000
#define DX  10

using namespace std;

void fact(int n, char* str){
    str[0] = 1;
    
    int i, j, r, ctn = 1;

    for(i = 2; i <= n; i++){
        j = 0;

        //0을 넘기려 하는 의도 같다
        while(!str[j]){
            j++;
        }
        
        for(r = 0; j < ctn ; j++){
            int k = str[j] * i + r;
            str[j] = k % DX;
            r = k / DX;
        }

        while(r){
            str[ctn++] = r % DX;
            r = r / DX;
        }
        
    }
    //print
    printf("\n");
    printf("값 = ");
    for(i = ctn - 1; i>= 0; i--)
    {
        printf("%d", str[i]);
    }
    printf("\n");
}

void fact2(int n, char *str)
{
    str[0] = 1;
    int i, j, k, r, cnt = 1;

    for(i = 2; i <= n; i++)
    {
        j = 0;
        while(!str[j]) j++;
        for(r = 0; j < cnt; j++)
        {
            k = str[j] * i + r;
            str[j] = k % DX;
            r = k / DX;
        }
        while(r)
        {
            str[cnt++] = r % DX;
            r /= DX;
        }
    }

    printf("자릿수 = %d, %d! = ", cnt, n);
    for(i = cnt - 1; i >= 0; i--)
    {
        printf("%d",str[i]);
    }
    printf("\n");
}

int main()
{
    int n = 18;
    char Fnum[MAX];

    fact(n, Fnum);

    return 0;
}