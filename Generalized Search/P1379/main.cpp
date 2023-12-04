#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef struct
{
    short board[3][3];
    short pos[2];
    int vec;
    ll step;
} stage;

short dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int target = 123804765;
set<int> visited;

void int2stage(int vec, stage *s_ptr)
{
    s_ptr->vec = vec;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int tmp = vec % 10;
            s_ptr->board[i][j] = (short)tmp;
            vec /= 10;
        }
    }
    return;
}

int stage2int(stage *s_ptr)
{
    if (s_ptr->vec)
        return s_ptr->vec;
    int vec = 0;
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            vec *= 10;
            vec += s_ptr->board[i][j];
        }
    }
    s_ptr->vec = vec;
    return vec;
}

void disp_stage(stage *s_ptr)
{
    for (int i = 2; i >= 0; i--)
    {
        for (int j = 2; j >= 0; j--)
        {
            cout << (s_ptr->board[i][j]) << " ";
        }
        cout << endl;
    }
    return;
}

void copy_board(stage *from, stage *to)
{
    stage &f = *from, &t = *to;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            t.board[i][j] = f.board[i][j];
        }
    }
    return;
}

ll bfs(stage *start_ptr)
{
    queue<stage *> q;
    q.push(start_ptr);
    visited.insert(start_ptr->vec);
    while (!q.empty())
    {
        stage &s = *(q.front());
        q.pop();
        //disp_stage(&s);
        //cout << "step:" << s.step << endl;
        short x = s.pos[0], y = s.pos[1];
        for (int i = 0; i < 4; i++)
        {
            short n_x = x + dx[i], n_y = y + dy[i];
            if (n_x < 0 || n_x > 2 || n_y < 0 || n_y > 2)
                continue;

            stage &tmp = *(new stage());
            tmp.vec = 0;
            copy_board(&s, &tmp);
            swap(tmp.board[x][y], tmp.board[n_x][n_y]);
            int key = stage2int(&tmp);
            tmp.pos[0] = n_x;
            tmp.pos[1] = n_y;
            tmp.step = s.step + 1;
            if (key == target)
                return tmp.step;
            if (visited.find(key) != visited.end()) 
            {
                delete &tmp;
                continue;
            }

            visited.insert(key);
            q.push(&tmp);
        }
    }
    return -1;
}

int main()
{
    int start;
    cin >> start;

    if (start == target)
    {
        cout << 0;
        return 0;
    }

    stage *start_ptr = new stage();
    int2stage(start, start_ptr);
    start_ptr->step = 0;
    start_ptr->vec = start;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!start_ptr->board[i][j])
            {
                start_ptr->pos[0] = i;
                start_ptr->pos[1] = j;
                break;
            }
        }
    }

    cout << bfs(start_ptr);
    return 0;
}