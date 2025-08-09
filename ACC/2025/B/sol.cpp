#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n, k; std::cin >> n >> k;

    std::vector<int> p(n + 1), idx(n + 1), ci(n + 1);
    std::vector<double> x(n + 1), y(n + 1), sr(n + 1), full(n + 1);
    std::vector<std::vector<double>> pref;

    std::vector<bool> in(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

//        if (in[p[i]])
//            assert(false);

        in[p[i]] = true;
    }

    for (int i = 1; i <= n; ++i)
        std::cin >> x[i] >> y[i];

    auto Dis = [&](int i, int j) {
        return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
    };

    std::vector<bool> used(n + 1), cyc(n + 1);

    auto Dfs = [&](auto &&self, int v) -> void {
        used[v] = true;

        int to = p[v];

        pref.emplace_back(std::vector<double>{0});

        int u = to, id = pref.size() - 1;
        cyc[v] = true;
        ci[v] = id;

        double sum = Dis(v, u);
        while (u != v) {
            cyc[u] = true;
            used[u] = true;
            idx[u] = pref.back().size();
            ci[u] = id;

            pref.back().emplace_back(sum);

            if (p[u] == v)
                sr[id] = Dis(u, p[u]);

            sum += Dis(u, p[u]);

            u = p[u];
        }

        full[id] = sum;
    };

    for (int i = 1; i <= n; ++i)
        if (!used[i])
            Dfs(Dfs, i);

    auto Get = [&](int v, int x) -> double {
        if (x <= 0)
            return 0.0;
        
        int u = ci[v], sz = pref[u].size();
        if (x < sz - idx[v])
            return pref[u][idx[v] + x] - pref[u][idx[v]];

        double res = pref[u].back() - pref[u][idx[v]] + sr[u];
        x -= (sz - idx[v]);

        res += (x / sz) * full[u];

        x %= sz;

        res += pref[u][x];

        return res;
    };

    std::vector<double> ans(n + 1);

    double res = -1;
    for (int i = 1; i <= n; ++i) {
        assert(cyc[i]);

        ans[i] = Get(i, k);

        if (res == -1 || res > ans[i])
            res = ans[i];
    }

    std::cout << std::fixed << std::setprecision(10) << res << '\n';
    return 0;
}
