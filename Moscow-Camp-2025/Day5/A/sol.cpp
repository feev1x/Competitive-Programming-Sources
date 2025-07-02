#include "grader.h"
#include <bits/stdc++.h>

int n, q, sq, _t;

std::vector<int> sz, tin, tout;
std::vector<int64_t> sum(2);
std::vector<bool> temp, used;
std::vector<std::vector<int>> g(2);
std::vector<std::pair<int, int>> qq;
std::vector<std::array<int, 20>> anc(2);

void init(int _q) {
    q = _q;
    n = 1;
    sq = sqrt(q);

    for (int i = 1; i < 20; ++i) {
        anc[0][i] = anc[1][i] = 1;
    }

    temp.resize(q + 1);
}

inline void dfs(int v) {
    used[v] = true;
    sz[v] = 1;
    tin[v] = ++_t;

    for (auto to: g[v]) {
        dfs(to);

        sz[v] += sz[to];
    }

    tout[v] = ++_t;
}

inline void build() {
    _t = 0;

    tin.resize(n + 1);
    tout.resize(n + 1);
    sz.resize(n + 1);
    used.assign(n + 1, false);

    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            continue;
        }

        dfs(i); 
    }

    tout[0] = ++_t;
}

void add_leaf(int p, int w) {
    int v = ++n;

    g.resize(v + 1);
    anc.resize(v + 1);

    sum.emplace_back(sum[p] + w);

    if (w < 0) {
        for (int i = 19; i >= 0; --i) {
            if (sum[v] < sum[anc[p][i]]) {
                p = anc[p][i];
            }
        }

        p = anc[p][0];
    }

    if (sum[v] < sum[p]) {
        p = v;
    }

    anc[v][0] = p;
    for (int i = 1; i < 20; ++i) {
        anc[v][i] = anc[anc[v][i - 1]][i - 1];
    }

    qq.emplace_back(p, v);

    if (qq.size() >= sq) {
        for (auto &[u, to]: qq) {
            if (u == to) {
                continue;
            }

            g[u].emplace_back(to);
        }

        qq.clear(); 
        build();
    }
}

int find_max(int v) {
    temp[v] = true;

    int res = v < sz.size() ? sz[v] : 1;
    for (auto &[u, to]: qq) {
        if (u == to) {
            continue;
        }

        if (temp[u] || u < tin.size() && v < tin.size() && tin[v] <= tin[u] && tout[u] <= tout[v]) {
            temp[to] = true;

            res++;
        }
    }

    for (auto &[u, to]: qq) {
        temp[to] = false;
    }

    temp[v] = false;

    return res;
}
