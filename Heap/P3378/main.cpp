#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;
int n = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op = 0, num = 0, out = 0;
        cin >> op;
        switch (op)
        {
            case 1:
                cin >> num;
                q.push(num);
                break;
            case 2:
                out = q.top();
                cout << out << '\n';
                break;
            case 3:
                q.pop();
                break;
        }
    }
}