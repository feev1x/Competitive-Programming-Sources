#include "bike.h"
#include <bits/stdc++.h>

std::pair<std::vector<int>, std::vector<long long>>
        find_rebalancing_strategy(int n, 
                                  std::vector<int> A, 
                                  std::vector<int> B, 
                                  std::vector<int> U,
                                  std::vector<int> V) {
    std::vector<int> X = {0};
    std::vector<long long> Y = {-1};
    std::vector<std::vector<int>> g(n);
    std::vector<int> nd(n), gv(n), cnt(n);
    for (int i = 0; i < n - 1; ++i) {
        g[U[i]].emplace_back(V[i]);
        g[V[i]].emplace_back(U[i]);
    }
    auto Dfs = [&](auto &&self, int v, int p) -> void {
        bool c = false;
        for (auto to: g[v]) if (to != p) {
            c = true;
            self(self, to, v);
        }
        if (!c) {
            nd[v] = std::max(0, B[v] - A[v]);
            gv[v] = std::min(0, A[v] - B[v]);
            return;
        }
        std::sort(g[v].begin(), g[v].end(), [&](int i, int j) {
            return nd[i] < nd[j];
        });
        int nw = A[v];
        for (auto to: g[v]) if (to != p) {
            if (gv[to] == 0 && nd[to] == 0 && cnt[to] == 0) continue;
            cnt[v] += cnt[to] + 1;
            if (nd[to] > nw) {
                nd[v] += nd[to] - nw;
                nw = nd[to];
            }
            nw = (nw - nd[to]) + gv[to];
        }
        gv[v] = std::min(0, nw - B[v]);
    }; Dfs(Dfs, 0, 0);
    X.resize(cnt[0]);
    Y.resize(cnt[0]);
    return {X, Y};
}
