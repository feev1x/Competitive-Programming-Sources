#include <bits/stdc++.h>

constexpr int N = 22;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, r; std::cin >> n >> r;

    std::vector<std::array<int, N>> anc(n + 1);
    for (auto &u: anc) {
        for (auto &v: u) {
            v = 0;
        }
    }

    std::vector<int> sub(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> anc[i][0];

        g[anc[i][0]].emplace_back(i);
    }

    {
        auto Dfs = [&](auto &&self, int v) -> void {
            sub[v] = 1;

            for (auto to: g[v]) {
                self(self, to);

                sub[v] += sub[to];
            }
        };

        Dfs(Dfs, r);
    }

    auto Dfs = [&](auto &&self, int v) -> void {
        for (int i = 1; i < N; ++i) {
            anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }

        for (auto to: g[v]) {
            self(self, to);
        }
    };

    anc[r][0] = r;
    Dfs(Dfs, r);

    int q; std::cin >> q;

    std::vector<int64_t> ans(q);
    for (int i = 0; i < q; ++i) {
        int k; std::cin >> k;

        int64_t a = k / n + (k % n > 0);


        k -= (a - 1) * n;
        int lc;
        if (sub[a] >= k) {
            lc = a;
        } else {
            int u = a;
            for (int i = N - 1; i >= 0; --i) {
                if (sub[anc[u][i]] < k) {
                    u = anc[u][i];
                }
            }

            lc = anc[u][0];
        }

        it 
    }


    return 0;
}
