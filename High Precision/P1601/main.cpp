#include <bits/stdc++.h>
#define MXN 505
using namespace std;

int n1, n2, mxn;
char str1[MXN], str2[MXN];
short num[MXN];

int main()
{
    scanf("%s", str1);
    scanf("%s", str2);
    n1 = strlen(str1);
    n2 = strlen(str2);
    if (n2 > n1)
    {
        swap(str1, str2);
        swap(n1, n2);
    }
    for (int i = 0; i < n1; i++)
    {
        num[i] = str1[n1 - i - 1] - '0';
    }
    for (int i = 0; i < n2; i++)
    {
        num[i] += str2[n2 - i - 1] - '0';
    }
    for (int i = 0; i < n1; i++)
    {
        if (num[i] >= 10) {
            num[i] -= 10;
            num[i + 1]++;
        }
    }
    for (int i = n1; i >= 0; i--)
    {
        if (i == n1 && num[i] == 0)
            continue;
        cout << num[i];
    }
}