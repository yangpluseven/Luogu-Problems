#include <bits/stdc++.h>
#define MXN 12000000
using namespace std;

char tmp[MXN], str[MXN << 1];
int len, r[MXN << 1];

void build_str()
{
    len = strlen(tmp);
    str[0] = '|';
    str[1] = '|';
    for (int i = 0; i < len; i++)
    {
        str[(i + 1) << 1] = tmp[i];
        str[((i + 1) << 1) + 1] = '|';
    }
    len = len * 2 + 2;
    str[len] = 0;
    return;
}

int manacher()
{
    int farthest = 0, mid = 0, i = 1, max_r = 1;
    for (int i = 1; i < len; i++)
    {
        if (i < farthest)
            r[i] = min(r[(mid << 1) - i], r[mid] + mid - i);
        else
            r[i] = 1;

        while (str[i - r[i]] == str[i + r[i]])
            r[i]++;
        
        max_r = max(max_r, r[i]);
        // cout << i << ":" << r[i] << endl;

        if (i + r[i] > farthest)
        {
            farthest = i + r[i];
            mid = i;
        }
    }
    return max_r;
}

int main()
{
    scanf("%s", &tmp);
    build_str();
    // for (int i = 0; i < strlen(str); i++)
    //     cout << str[i];
    // cout << endl;
    int ans = manacher() - 1;
    cout << ans;
    return 0;
}