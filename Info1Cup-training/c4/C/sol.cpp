/**
 *    author:  feev1x
 *    created: 31.01.2025 11:36:15
**/
#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline void sub_self(int &a, int b) {
    a -= b;
    
    if (a < 0) {
        a += MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k; std::cin >> n >> m >> k;

    std::vector<int> a(n + 1), sum(n + 1);
    std::vector<std::vector<int>> p(k + 1, std::vector<int>(n + 1));
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    std::vector<bool> nw(n + 1);
    auto Dfs = [&](auto &&self, int v) -> void {
        nw[v] = true;

        for (auto to: g[v]) {
            bool flag = !nw[to];
            for (int i = 1; i <= k; ++i) {
                if (to == p[i][v]) {
                    flag = false;

                    break;
                }
            }

            if (!flag) {
                continue;
            }


            if (p[1][to] == 0) {
                p[1][to] = v;

                self(self, to);
            } else {
                for (int i = 1; i <= k; ++i) {
                    if (p[i][to] == 0) {
                        p[i][to] = v;

                        break;
                    }

                    assert(i != k);
                }
            }

            sum[v] += a[to];
        }

        nw[v] = false;
    };

    Dfs(Dfs, 1);

    int q; std::cin >> q;
    while (q--) {
        int v; std::cin >> v;

        for (int i = 1; i <= k; ++i) {
            sub_self(sum[p[i][v]], a[v]);
        }

        add_self(a[v], sum[v]);
        for (int i = 1; i <= k; ++i) {
            add_self(a[v], a[p[i][v]]);
        }

        for (int i = 1; i <= k; ++i) {
            add_self(sum[p[i][v]], a[v]); 
        }

        std::cout << a[v] << '\n';
    }
    return 0;
}
