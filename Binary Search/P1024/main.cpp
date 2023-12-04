#include <bits/stdc++.h>
#define E 0.001
using namespace std;

double a, b, c, d;

double func(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

double binary_search(double l, double r)
{
    double mid;
    while (r - l >= E)
    {
        mid = (l + r) / 2.0;
        if (func(mid) * func(l) < 0.0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}

int main()
{
    cin >> a >> b >> c >> d;
    for (double f = -100.0; f < 100.0; f += 1.0)
    {
        if (func(f) * func(f + 1.0) < 0)
        {
            double ans = binary_search(f, f + 1.0);
            printf("%.2lf ", ans);
        }
        if (func(f) == 0)
        {
            printf("%.2lf ", f);
        }
    }
    if (func(100.0) == 0)
    {
        printf("%lf.2f ", 100.0);
    }
    return 0;
}