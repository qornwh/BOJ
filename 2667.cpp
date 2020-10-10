#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class node
{
public:
    bool n;
    bool vist;
};

int num;
int arry;
node box[25][25];

void dfs(int x, int y)
{
    int i = x;
    int j = y;
    if (i < 25 && j < 25 && i >= 0 && j >= 0)
    {
        box[x][y].vist = true;
        arry++;
        if (box[i][j - 1].n == true && box[i][j - 1].vist == false)
        {
            dfs(i, j - 1);
        }
        if (box[i][j + 1].n == true && box[i][j + 1].vist == false)
        {
            dfs(i, j + 1);
        }
        if (box[i - 1][j].n == true && box[i - 1][j].vist == false)
        {
            dfs(i - 1, j);
        }
        if (box[i + 1][j].n == true && box[i + 1][j].vist == false)
        {
            dfs(i + 1, j);
        }
    }
}

int main()
{
    int count = 0;
    int arr_cnt[313];

    cin >> num;

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            scanf("%1d", &box[i][j].n);
        }
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (box[i][j].n && box[i][j].vist == false)
            {
                dfs(i, j);
                arr_cnt[count] = arry;
                count++;
                arry = 0;
            }
        }
    }

    cout << count << endl;
    sort(arr_cnt, arr_cnt + count);
    for (int i = 0; i < count; i++)
    {
        cout << arr_cnt[i] << " " << endl;
    }

    return 0;
}