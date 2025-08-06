/**
 *    author:  feev1x
 *    created: 02.08.2025 13:39:39
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1), d(n + 1), idx(n + 1), ci(n + 1), qv(n + 1), head(n + 1), sz(n + 1, 1), fq(n + 1);
    std::vector<int64_t> ans(n + 1), cost(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        ci[i] = head[i] = i;
        g[a[i]].emplace_back(i);
    }

    std::vector<bool> used(n + 1), ins(n + 1), cyc(n + 1), ask(n + 1);
    auto Cyc = [&](auto &&self, int v) -> void {
        used[v] = true;
        ins[v] = true;

        int to = a[v];

        if (ins[to]) {
            int u = to;
            cyc[v] = true;

            idx[u] = 1;
            while (u != v) {
                cyc[u] = true;

                sz[v]++;
                ci[u] = v;

                idx[a[u]] = idx[u] + 1;
                u = a[u];
            }
            
            u = to;
            while (u != v) {
                sz[u] = sz[v];

                u = a[u];
            }
        } else if (used[to]) {
            d[v] = d[to] + 1;
            head[v] = head[to];
        } else {
            self(self, to);

            if (!cyc[v])
                d[v] = d[to] + 1, head[v] = head[to];
        }

        ins[v] = false;
    };

    for (int i = 1; i <= n; ++i)
        if (!used[i])
            Cyc(Cyc, i);

    auto Dis = [&](int i, int j) {
        if (idx[j] >= idx[i])
            return idx[j] - idx[i];

        return sz[ci[i]] - idx[i] + idx[j];
    };

    int q; std::cin >> q;
    while (q--) {
        int b; std::cin >> b;

        if (cyc[b] && qv[ci[b]])
            cost[ci[b]] += Dis(qv[ci[b]], b);
        else if (cyc[b])
            fq[ci[b]] = b;

        if (cyc[b])
            qv[ci[b]] = b;

        ask[b] = true;
    }

    for (int i = 1; i <= n; ++i)
        if (cyc[i] && qv[ci[i]])
            ans[i] = Dis(i, fq[ci[i]]) + cost[ci[i]];

    auto Dfs = [&](auto &&self, int v, int cost) -> void {
        if (ask[v])
            if (cost == -1)
                cost = 0;

        if (cost != -1)
            ans[v] = cost;
        else
            ans[v] = 0;

        for (auto to: g[v])
            self(self, to, (cost == -1 ? -1 : cost + 1));
    };

    for (int i = 1; i <= n; ++i)
        if (d[i] == 1 && !cyc[i] && !qv[ci[head[i]]])
            Dfs(Dfs, i, -1);
        else if (!cyc[i] && qv[ci[head[i]]])
            ans[i] = ans[head[i]] + d[i];

    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];

    return 0;
}
