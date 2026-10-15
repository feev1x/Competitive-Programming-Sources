#include "evilution.h"
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
std::vector<std::vector<long long>> solve(std::string ss, std::vector<std::string> s2, std::vector<long long> k, std::vector<long long> l, std::vector<long long> r) {
    int q = k.size();
    std::vector<std::vector<long long>> res(q, std::vector<long long>(4));
    std::map<char, int> idx;
    idx['A'] = 0, idx['C'] = 1, idx['G'] = 2, idx['T'] = 3;
    std::vector<std::string> s(11);
    std::vector p(11, std::vector<std::vector<int>>(4));
    s[0] = ss;
    int i = 0;
    for (auto u: s[i]) {
        for (int j = 0; j < 4; ++j) p[i][j].emplace_back(p[i][j].size() ? p[i][j].back() : 0);
        p[i][idx[u]].back()++;
    }
    for (int i = 1; i < 11; ++i) {
        for (auto u: s[i - 1]) s[i] += s2[idx[u]];
        for (auto u: s[i]) {
            for (int j = 0; j < 4; ++j) p[i][j].emplace_back(p[i][j].size() ? p[i][j].back() : 0);
            p[i][idx[u]].back()++;
        }
    }
    for (int i = 0; i < q; ++i)
        for (int j = 0; j < 4; ++j) res[i][j] = p[k[i]][j][r[i]] - (l[i] ? p[k[i]][j][l[i] - 1] : 0);
    return res;
}
