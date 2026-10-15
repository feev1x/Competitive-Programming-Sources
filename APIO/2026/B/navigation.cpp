#include "navigation.h"
#include <bits/stdc++.h>

namespace {
// you can store information in the global scope,
// but construct_network and navigate run in different process; they won't be able to share the data
int count = 0;
} // namespace

std::vector<int> construct_network(int n, int k, int b, std::vector<int> U,
                                   std::vector<int> V, std::vector<int> p) {
    std::vector<std::vector<std::pair<int, int>>> g(n);
    std::vector<int> tin(n), tout(n), dep(n), t(n - 1), par(n);
    std::vector<bool> used(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        g[U[i]].emplace_back(V[i], i);
        g[V[i]].emplace_back(U[i], i);
    }
    int _t = 0;
    dep[0] = -1;
    {
        auto Dfs = [&](auto &&self, int v) -> void {
            tin[v] = ++_t;
            dep[v] = dep[par[v]] + 1;
            for (auto [to, i]: g[v]) if (to != par[v]) {
                par[to] = v;
                self(self, to);
            }
            tout[v] = ++_t;
        }; Dfs(Dfs, 0);
    }
    auto Dfs = [&](auto &&self, int v, int empt) -> void {
        int idx = -1;
        for (auto [to, i]: g[v]) if (to == par[v]) idx = i;
        if (empt == 1) {
            for (auto [to, i]: g[v]) if (to != par[v]) {
                t[i] = (t[idx] + 1) % 4;
                self(self, to, true);
            }
            return;
        }
        std::vector<int> c, pv;
        for (auto [to, i]: g[v]) {
            int cnt = 0;
            for (auto u: p) if (to != par[v] && tin[to] <= tin[u] && tout[u] <= tout[to] || to == par[v] && !(tin[v] <= tin[u] && tout[u] <= tout[v])) cnt++;
            c.emplace_back(cnt);
            if (cnt) pv.emplace_back(cnt);
            if (cnt == 6) {
                self(self, to, false);
                for (auto [to2, i2]: g[v]) if (to2 != to) {
                    t[i2] = (t[i] + 1) % 4;
                    self(self, to2, true);
                }
                return;
            }
        }
        std::sort(pv.begin(), pv.end());
        for (int i = 0; i < c.size(); ++i) {
            if (g[v][i].first == par[v]) {
                if (c[i]) {
                    if (t[g[v][i].second] == c[i]) for (int i = 0; i < c.size(); ++i) t[g[v][i].second] = c[i];
                    else for (int i = 0; i < c.size(); ++i) t[g[v][i].second] = (k - c[i]) % k;
                } else for (int i = 0; i < c.size(); ++i) t[g[v][i].second] = c[i];
                break;
            }
        }
        if (par[v] == v) for (int i = 0; i < c.size(); ++i) t[g[v][i].second] = c[i];
        for (int i = 0; i < c.size(); ++i) if (g[v][i].first != par[v]) self(self, g[v][i].first, c[i] == 0); 
    }; Dfs(Dfs, 0, 0);
    return t;
}

std::vector<int> navigate(int k, int b, std::vector<int> c) {
    std::vector<int> d(c.size());
    int64_t sum = 0;
    for (auto u: c) {
        sum += u;
    }
    if (sum == k) {
        return c;
    }
    sum = 0;
    for (auto u: c) {
        sum += (k - u) % k;
    }
    if (sum == k) {
        for (auto &u: c) u = (k - u) % k;
        return c;
    }
    int v1 = -1, v2 = -1, v3 = -1;
    for (auto u: c) {
        if (v1 == -1) v1 = u;
        else if (v2 == -1 && u != v1) v2 = u;
        else if (u != v1 && u != v2) v3 = u;
    }
    if (v3 == -1) {
        if ((v1 + 1) % 4 == v2) std::swap(v1, v2);
        for (auto &u: c) u = (u == v1 ? 6 : 0);
        return c;
    } else {
        if ((v1 + 1) % 6 == v2) {
            for (auto &u: c) {
                if (u == v1) u = (v2 + 2) % 6 == v3 ? 5 : 4;
                else if (u == v2) u = (v2 + 2) % 6 == v3 ? 1 : 2;
                else u = 0;
            }
        } else if ((v1 + 1) % 6 == v3) {
            for (auto &u: c) {
                if (u == v1) u = (v3 + 2) % 6 == v2 ? 5 : 4;
                else if (u == v3) u = (v3 + 2) % 6 == v2 ? 1 : 2;
                else u = 0;
            }
        } else if ((v2 + 1) % 6 == v1) {
            for (auto &u: c) {
                if (u == v2) u = (v1 + 2) % 6 == v3 ? 5 : 4;
                else if (u == v1) u = (v1 + 2) % 6 == v3 ? 1 : 2;
                else u = 0;
            }
        } else if ((v2 + 1) % 6 == v3) {
            for (auto &u: c) {
                if (u == v2) u = (v3 + 2) % 6 == v1 ? 5 : 4;
                else if (u == v3) u = (v3 + 2) % 6 == v1 ? 1 : 2;
                else u = 0;
            }
        } else if ((v3 + 1) % 6 == v1) {
            for (auto &u: c) {
                if (u == v3) u = (v1 + 2) % 6 == v2 ? 5 : 4;
                else if (u == v1) u = (v1 + 2) % 6 == v2 ? 1 : 2;
                else u = 0;
            }
        } else {
            for (auto &u: c) {
                if (u == v3) u = (v2 + 2) % 6 == v1 ? 5 : 4;
                else if (u == v2) u = (v2 + 2) % 6 == v1 ? 1 : 2;
                else u = 0;
            }
        }
        return c;
    }
}
