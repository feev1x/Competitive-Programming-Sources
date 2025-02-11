/**
 *    author:  feev1x
 *    created: 10.02.2025 15:29:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cout << std::fixed << std::setprecision(10);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int k; std::cin >> k;

        a[i].resize(k);

        for (auto &u: a[i]) {
            std::cin >> u;
        }
    }

    long double res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            std::map<int, int> mp1, mp2;

            int k1 = a[i].size(), k2 = a[j].size();
            for (auto &u: a[i]) {
                mp1[u]++;
            }

            for (auto &u: a[j]) {
                mp2[u]++;
            }

            long double prob = 0;
            for (auto [key, val]: mp1) {
                prob += (val / (long double)k1) * (mp2[key] / (long double)k2);
            }

            res = std::max(res, prob);
        }
    }

    std::cout << res << '\n';
    return 0;
}
