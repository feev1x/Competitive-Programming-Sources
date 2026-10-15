#include "triangle.h"
#include <bits/stdc++.h>

std::vector<int> solve(int n) {
    std::vector<std::vector<bool>> a(n, std::vector<bool>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) a[i][j] = query(i, i, j);
    std::vector<int> l(n), r(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) l[i] += !a[j][i];
        l[i] *= 2, r[i] = std::min(l[i] + 1, n);
    }
    std::vector<int> idx(n + 1), sm;
    for (int i = 0; i < n; ++i) {
        if (l[i] * 2 > n && l[i] < r[i]) sm.emplace_back(i);
        else if (l[i] < r[i]) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) cnt += a[i][j];
            l[i] = r[i] = cnt / 2, idx[cnt / 2] = i;
        }
    }
    for (auto i: sm) {
        bool c = query(idx[l[i] / 2], idx[l[i] / 2 + 1], i);
        if (c) r[i] = l[i];
        else l[i] = r[i];
    }
    return l;
}
