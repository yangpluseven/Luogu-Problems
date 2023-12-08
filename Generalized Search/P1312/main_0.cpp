#include <bits/stdc++.h>
#define MXN 5
#define MXC 10
using namespace std;

short n, grid[7][5], steps[MXN][3], movement[2] = {1, -1};

void grid_print(short g[7][5])
{
    cout << '\n';
    for (int i = 6; i >= 0; i--)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}

void grid_copy(short form[7][5], short to[7][5])
{
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
            to[i][j] = form[i][j];
}

bool fall(short g[7][5])
{
    bool changed = false;
    for (int i = 0; i < 5; i++)
    {
        short blank_idx = -1;
        for (int j = 0; j < 7; j++)
        {
            if (!g[j][i] && blank_idx < 0)
            {
                blank_idx = j;
                continue;
            }
            if (blank_idx >= 0 && g[j][i])
            {
                g[blank_idx][i] = g[j][i];
                g[j][i] = 0;
                blank_idx++;
                changed = true;
            }
        }
    }
    return changed;
}

bool eliminate(short g[7][5])
{
    bool should_eli[7][5], flag = false;
    memset(should_eli, false, sizeof(should_eli));
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
        {
            if (i - 1 >= 0 && i + 1 < 7 && g[i][j] == g[i - 1][j] && g[i][j] == g[i + 1][j] && g[i][j])
            {
                should_eli[i - 1][j] = true;
                should_eli[i + 1][j] = true;
                should_eli[i][j] = true;
                flag = true;
            }
            if (j - 1 >= 0 && j + 1 < 5 && g[i][j] == g[i][j + 1] && g[i][j] == g[i][j - 1] && g[i][j])
            {
                should_eli[i][j] = true;
                should_eli[i][j + 1] = true;
                should_eli[i][j - 1] = true;
                flag = true;
            }
        }
    if (!flag)
        return false;
    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 5; j++)
            if (should_eli[i][j])
                g[i][j] = 0;
    return true;
}

void simulate(short g[7][5])
{
    eliminate(g);
    while (fall(g))
    {
        eliminate(g);
    }
}

bool check(short g[7][5])
{
    for (int i = 0; i < 5; i++)
        if (g[0][i])
            return false;
    return true;
}

bool find_solution(short g[7][5], short s)
{
    if (s > n)
    {
       // grid_print(g);
        return false;
    }

    simulate(g);

    if (s == n && check(g))
    {
        // grid_print(g);
        return true;
    }

    bool found = false;
    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 7; i++)
        {
            if (g[i][j])
            {
                for (int k = 0; k < 2; k++)
                {
                    short tmpg[7][5];
                    short nj = j + movement[k];
                    if (nj >= 0 && nj < 5)
                    {
                        if (movement[k] < 0 && g[i][nj])
                            continue;
                        grid_copy(g, tmpg);
                        swap(tmpg[i][j], tmpg[i][nj]);
                        // cout << s << ':' << j << ' ' << i << ' ' << movement[k] << '\n';
                        found = find_solution(tmpg, s + 1);
                        if (found)
                        {
                            steps[s][0] = j;
                            steps[s][1] = i;
                            steps[s][2] = movement[k];
                            // grid_print(g);
                            break;
                        }
                    }
                }
                if (found)
                    break;
            }
        }
        if (found)
            break;
    }
    return found;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < 5; i++)
    {
        short tmp = 1, j = 0;
        while (true)
        {
            cin >> tmp;
            if (tmp == 0)
                break;
            grid[j][i] = tmp;
            j++;
        }
    }

    // grid_print(grid);

    if (!find_solution(grid, 0))
    {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << steps[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}

// int main() // for test
// {
//     for (int i = 0; i < 5; i++)
//     {
//         short tmp = 1, j = 0;
//         while (true)
//         {
//             cin >> tmp;
//             if (tmp == 0)
//                 break;
//             grid[j][i] = tmp;
//             j++;
//         }
//     }

//     simulate(grid);
//     grid_print(grid);
// }