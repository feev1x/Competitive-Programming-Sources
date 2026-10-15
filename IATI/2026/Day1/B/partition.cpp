#include "partition.h"
#include <bits/stdc++.h>

constexpr int N = 33554432;
int val[N + 5];
bool did;

std::vector<int> solve(std::vector<int> a) {
    if (!did) {
        did = true;
        int vl = 1;
        for (int i = 0; i < 26; ++i) val[vl] = i, vl += vl;
    }
    int n = a.size();
    if (n == 1) return {0};
    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return a[i] < a[j];
    });
    if (n == 2) return {idx[1], idx[0]};
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) sum += a[i];
    int64_t sm = 0, nd = (sum + 1) / 2;
    int optl = 0, optr = (n + 1) / 2 - 2;
    for (int i = optl; i <= optr; ++i) sm += a[idx[i]];
    while (sm < nd - a.back()) {
        sm -= a[idx[optl++]];
        sm += a[idx[++optr]];
    }
    std::vector<int> res2;
    for (int i = optl; i <= optr; ++i) res2.emplace_back(idx[i]);
    res2.emplace_back(idx[n - 1]);
    for (int i = 0; i < optl; ++i) res2.emplace_back(idx[i]);
    for (int i = optr + 1; i + 1 < n; ++i) res2.emplace_back(idx[i]);
    return res2;
}
