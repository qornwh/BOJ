#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    string org;
    string cmp;
    int count = 0;
    int pos = 0;

    getline(cin, org);
    getline(cin, cmp);

    int org_len = org.length();
    int cmp_len = cmp.length();

    if (org_len >= cmp_len)
    {
        org_len = org_len - cmp_len;

        for (int j = 0; j <= org_len; j++)
        {
            pos = 0;
            for (int i = 0; i < cmp_len; i++)
            {
                if (org[j+pos] != cmp[i])
                {
                    break;
                }
                else if (i == cmp_len - 1)
                {
                    count++;
                    j += pos;
                    break;
                }
                pos++;
            }
        }
    }
 
    cout << count;

    return 0;
}