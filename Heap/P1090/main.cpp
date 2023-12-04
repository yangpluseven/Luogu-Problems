#include "bits/stdc++.h"
using namespace std;

auto cmp = [](const int &a, const int &b) -> bool
{
    return a > b;
};

priority_queue<int, vector<int>, decltype(cmp)> q(cmp);

int main()
{
    int n, cost = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        q.push(tmp);
    }
    while (q.size() > 1)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        int sum = a + b;
        cost += sum;
        q.push(sum);
    }
    cout << cost;
    return 0;
}