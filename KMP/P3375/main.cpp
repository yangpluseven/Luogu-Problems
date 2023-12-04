#include <bits/stdc++.h>
#define MXN 1000005
using namespace std;

char s1[MXN], s2[MXN];
int retreat[MXN], indices[MXN];
int len_s1, len_s2;

void build_retreat()
{
    retreat[0] = 0;
    retreat[1] = 0;
    int i = 2, j = 0;
    while (i <= len_s2)
    {
        if (s2[i - 1] != s2[j])
        {
            if (j == 0)
            {
                retreat[i] = 0;
                i++;
            }
            j = retreat[j];
        }
        else
        {
            j++;
            retreat[i] = j;
            i++;
        }
    }
    return;
}

int main()
{
    cin >> s1 >> s2;
    len_s1 = strlen(s1);
    len_s2 = strlen(s2);
    build_retreat();

    int i = 0, j = 0, cnt = 0;
    while (i <= len_s1)
    {
        // cout << "i:" << i << " j:" << j << endl;
        if (j >= len_s2)
        {
            j = retreat[len_s2];
            if (j >= len_s2)
                j = 0;
            indices[cnt] = i - len_s2;
            // cout << "find:" << indices[cnt] << endl;
            cnt++;
        }
        if (s1[i] != s2[j])
        {
            if (j == 0)
                i++;
            j = retreat[j];
            // cout << "retreat:" << j << endl;
        }
        else
        {
            i++;
            j++;
            // cout << "ok" << endl;
        }
    }

    for (int k = 0; k < cnt; k++)
    {
        cout << indices[k] + 1 << endl;
    }

    for (int k = 1; k <= len_s2; k++)
    {
        cout << retreat[k] << ' ';
    }
    return 0;
}