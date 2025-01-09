/**
 *    author:  feev1x
 *    created: 09.01.2025 10:24:45
**/
#include <bits/stdc++.h>

void print(__int128 x) {
    if (x < 0) {
        std::cout << '-';
        x = -x;
    }
    if (x > 9) print(x / 10);
    std::cout << (short)(x % 10);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t; std::cin >> n >> t;

    std::vector<int> p(n + 1), a(n + 1);
    std::vector<__int128> dp(n + 1), dp1(n + 1), sum_v(n + 1), sz(n + 1, 1), dep(n + 1), mxdep(n + 1);
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        std::cin >> p[i] >> a[i];

        g[p[i]].emplace_back(i);
        g[i].emplace_back(p[i]);
    }

    auto Calc = [&](auto &&self, int v, int par) -> void {
        sum_v[v] = a[v];
        dep[v] = dep[par] + 1;
        mxdep[v] = dep[v];
        p[v] = par;

        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            self(self, to, v);

            sum_v[v] += sum_v[to];
            sz[v] += sz[to];
            mxdep[v] = std::max(mxdep[v], mxdep[to]);
        }
    };

    Calc(Calc, 1, 0);

    auto Dfs = [&](auto &&self, int v) -> void {
        std::vector<std::pair<__int128, int>> add;

        for (auto to: g[v]) {
            if (to == p[v]) {
                continue;
            }

            self(self, to);

            add.emplace_back(sum_v[to], to);
            dp[v] += dp[to];
        }

        if (add.empty()) {
            return;
        }

        dp1[v] = dp[v];

        std::sort(add.begin(), add.end(), [&](std::pair<__int128, int> x, std::pair<__int128, int> y) {
            return sz[x.second] * y.first < sz[y.second] * x.first;
        });

        __int128 res = 0, num = 1, res1 = 0;

        for (int i = 0; i < add.size(); ++i) {
            res += add[i].first * num;
            num += sz[add[i].second] * 2;
        }

        dp[v] += res;
        if (t == 1 && mxdep[1] == mxdep[v]) {
            int opt = -1, i = 0;
            long double al = -1;

            for (auto &[u, to]: add) {
                if (mxdep[to] == mxdep[1]) {
                    if (al < sz[to] / (long double)(u + (long double)(dp1[to] - dp[to]))) {
                        al = sz[to] / (long double)(u + (long double)(dp1[to] - dp[to]));
                        opt = i;
                    }
                }

                i++;
            }

            assert(opt != -1);

            std::swap(add[opt], add.back());
            std::sort(add.begin(), add.end() - 1, [&](std::pair<__int128, int> x, std::pair<__int128, int> y) {
                return sz[x.second] * y.first < sz[y.second] * x.first;
            });

            res = 0, num = 1;

            for (int i = 0; i < add.size(); ++i) {
                res += add[i].first * num;
                num += sz[add[i].second] * 2;
            }

            res1 = res;

            res1 += dp1[add.back().second] - dp[add.back().second];

            dp1[v] += res1;
        }

//        std::cout << v << ' '; print(dp[v]); std::cout << ' '; print(dp1[v]); std::cout << '\n';
    };

    Dfs(Dfs, 1);

    if (t == 0) {
        mxdep[1] = 1;
        dp1[1] = dp[1];
    }

    std::cout << (n - 1) * 2 - (int)mxdep[1] + 1 << ' '; print(dp1[1]); std::cout << '\n';
    return 0;
}
