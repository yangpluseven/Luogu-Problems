#include <iostream>
#include <algorithm>
#define MXN 65

bool used[MXN], cant[MXN * 50 + 1];
int n, sticks[MXN];

bool dfs(int tar, int idx) {
    if (tar == 0) {
        return true;
    }
    if (tar < 0 || cant[tar]) return false;
    for (int i = idx + 1; i < n; i++) {
        if (used[i] || tar < sticks[i]) continue;
        used[i] = true;
        bool res = dfs(tar - sticks[i], i);
        if (res) return true;
        used[i] = false;
    }
    cant[tar] = true;
    return false;
}

int main() {
    memset(sticks, 0, sizeof(sticks));
    int maxL = 0, sumL = 0;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> sticks[i];
        maxL = std::max(maxL, sticks[i]);
        sumL += sticks[i];
    }

    std::sort(sticks, sticks + n, [](const int& a, const int& b)->bool{
        return a > b;
    });

    for (int i = maxL; i <= sumL / 2; i++) {
        if (sumL % i != 0) continue;
        memset(cant, 0, sizeof(cant));
        memset(used, 0, sizeof(used));
        bool res = false;
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            used[j] = true;
            res = dfs(i - sticks[j], j);
            if (!res) {
                break;
            }
        }
        if (res) {
            std::cout << i;
            return 0;
        }
    }
    std::cout << sumL;
    return 0;
}