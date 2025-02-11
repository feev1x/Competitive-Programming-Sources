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

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    std::set<int64_t> res;

    auto Dfs = [&](auto &&self, std::map<int64_t, int> st, int i) {
        if (i == n) {
            int64_t xr = 0;

            for (auto [key, val]: st) {
                xr ^= key * (val & 1);
            }


            res.emplace(xr);

            return;
        }

        auto s = st;
        for (auto [key, val]: st) {
            s[key]--;

            if (!s[key]) {
                s.erase(key);
            }

            s[key + a[i]]++;

            self(self, s, i + 1);

            s[key + a[i]]--;
            if (!s[key + a[i]]) {
                s.erase(key + a[i]);
            }

            s[key]++;
        }

        s[a[i]]++;

        self(self, s, i + 1);
    };

    Dfs(Dfs, {}, 0);

    std::cout << res.size() << '\n';
    return 0;
}
