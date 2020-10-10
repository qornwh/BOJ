#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <vector>

using namespace std;

const int DX = 1000000000;
const int DIGTS = 9;

void fact(int n, vector<int> &vi)
{
    int i, j, cnt;
    __int64 r;
    time_t t1, t2;

    t1 = clock();
    vi.push_back(1);

    for(i = 2; i <= n; i++)
    {
        j = 0;
        while(!vi[j]) j++;

        for(r = 0; j < vi.size(); j++)
        {
            r += (__int64)i * vi[j];
            vi[j] = r % DX;
            r /= DX;
        }
        while(r)
        {
            vi.push_back(r % DX);
            r /= DX;
        }
    }
    t2 = clock();
    printf("계산시간 = %.3fsec\n", (t2 - t1)/1000.);
}

int Print(int n, vector<int> vi)
{
    int i, tmp, cnt, digts = 0;
    cnt = vi.size() - 1;
    tmp = vi[cnt];

    while(tmp)
    {
        digts++;
        tmp /= 10;
    }
    digts += cnt * DIGTS;

    printf("자릿수 = %d, %d! = ", digts, n);

    int N = 0;
    printf("%d",vi[cnt--]);
    for (i = cnt; i >= 0; i--)
    {
        printf("%0*d",DIGTS,vi[i]);
        if(++N > 100) break;
    }
    printf("\n");    FILE *f;


    return digts;
}

void Save(int n, vector<int> vi, int digts)
{
    int i, cnt;
    char ch, str[20];
    FILE *f;

    while(1)
    {
        printf("file로 저장하시겠습니까? y/n : \n");
        ch = getch();
        if(ch == 'n' || ch == 'N') return;
        else if(ch == 'y' || ch == 'Y') break;
        else printf("n or y를 선택하세요\n");
    }

    sprintf(str, "c:\\%d!.txt",n);
    f=fopen(str,"wt");

    cnt = vi.size() - 1;
    if (f != NULL)
    {
        printf("파일 저장중입니다.\n");
        fprintf(f, "자릿수 = %d, %d! = %d", digts, n, vi[cnt--]);
        for (i = cnt; i >= 0; i--)
        {
             fprintf(f, "%0*d",DIGTS,vi[i]);
        }
        fclose(f);
        printf("파일 저장이 완료되었습니다.\n");
    }
}

int main()
{
    int n, digts;
    vector<int> vi;

    printf("팩토리얼 계산 프로그램입니다.\n계산할 숫자를 입력하세요 : ");
    scanf("%d", &n);
    fflush(stdin);
    if(n <= 0) return 0;

    fact(n, vi);
    digts = Print(n, vi);
    Save(n, vi, digts);
    vi.clear();

    return 0;
}