/**
 *    author:  feev1x
 *    created: 29.01.2025 20:54:55
**/
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n), gr(n + 1);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    std::unordered_set<int64_t> res;

    auto Dfs = [&](auto &&self, int cnt, int i) {
        if (i == n) {
            int64_t xr = 0;

            for (int i = 1; i <= cnt; ++i) {
                xr ^= gr[i];
            }


            res.emplace(xr);

            return;
        }

        for (int j = 1; j <= cnt + 1; ++j) {
            gr[j] += a[i];

            self(self, std::max(j, cnt), i + 1);

            gr[j] -= a[i];
        }
    };

    Dfs(Dfs, 0, 0);

    std::cout << res.size() << '\n';
    return 0;
}
