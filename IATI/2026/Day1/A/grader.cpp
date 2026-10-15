#include "infection.h"
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

std::vector<int> solve(
    std::vector<std::pair<int, int>> R,
    std::vector<long long> D,
    std::vector<int> S,
    std::vector<int> T,
    std::vector<bool> I
) {
    int n = R.size() + 1, m = D.size();
    std::vector<std::vector<int>> g(n);
    for (auto [u, v]: R) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    std::vector<int> par(n), tin(n), tout(n), ans(m);
    int _t = 0;
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        tin[v] = ++_t;
        par[v] = p;
        for (auto to: g[v]) if (to != p) self(self, to, v);
        tout[v] = ++_t;
    }; Dfs(Dfs, 0, 0);
    std::vector<int> mp;
    for (int i = 0; i < m; ++i) mp.emplace_back(i);
    std::sort(mp.begin(), mp.end(), [&](int i, int j) {
        return D[i] > D[j];
    });
    std::vector<int> nw;
    std::vector<bool> inf(n);
    int tm = 0, cnt = 0;
    while (cnt < m) {
        if (nw.empty()) assert(mp.size()), tm = D[mp.back()];
        while (mp.size() && D[mp.back()] == tm) nw.emplace_back(mp.back()), mp.pop_back();
        for (auto i: nw) if (I[i]) inf[S[i]] = 1;
        for (auto i: nw) I[i] = inf[S[i]];
        for (auto i: nw) inf[S[i]] = 0;
        for (auto i: nw) ans[i] += I[i];
        std::vector<int> new_nw;
        for (auto i: nw) {
            if (S[i] == T[i]) {
                cnt++;
                continue;
            }
            if (tin[S[i]] <= tin[T[i]] && tout[T[i]] <= tout[S[i]]) {
                for (auto to: g[S[i]]) {
                    if (tin[to] <= tin[T[i]] && tout[T[i]] <= tout[to] && to != par[S[i]]) {
                        S[i] = to;
                        break;
                    }
                }
            } else S[i] = par[S[i]];
            new_nw.emplace_back(i);
        }
        tm++;
        std::swap(nw, new_nw);
    }
    return ans;
}

signed main() {
    int n, m;

    std::cin >> n;
    std::cin >> m;

    std::vector<std::pair<int, int>> edges = {};
    std::vector<long long> day;
    std::vector<int> start;
    std::vector<int> target;
    std::vector<bool> infected;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        edges.emplace_back(u, v);
    }

    for (int i = 0; i < m; i++) {
        long long _d, _s, _t, _i;
        std::cin >> _d >> _s >> _t >> _i;
        day.push_back(_d);
        start.push_back(_s);
        target.push_back(_t);
        infected.push_back(_i);
    }

    const auto ans = solve(edges, day, start, target, infected);
    for (const auto it : ans) {
        std::cout << it << std::endl;
    }

    return 0;
}
