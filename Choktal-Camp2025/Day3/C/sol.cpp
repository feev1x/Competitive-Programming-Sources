/**
 *    author:  feev1x
 *    created: 03.07.2025 12:35:59
**/
#include <bits/stdc++.h>

inline void cout(__int128 x) {
    if (x > 9) {
        cout(x / 10);
    }

    std::cout << int(x % 10);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> x(n + 1);
    std::vector<__int128> all, cost;
    for (int i = 1; i <= n; ++i) {
        std::cin >> x[i];
    }

    int64_t d; std::cin >> x[0] >> d;

    int m; std::cin >> m;
    if (m > 1) {
        for (int i = 0; i <= n; ++i) {
            int64_t f = (x[i] - x[0]) / d;

            f = (f * d) + x[0];

            all.emplace_back(f);
            all.emplace_back(f + d);
            all.emplace_back(f - d);
        }

        std::sort(all.begin(), all.end());

        while (m--) {
            int64_t t; std::cin >> t;

            __int128 res = 1e32;
            std::vector<std::vector<__int128>> ans(all.size(), std::vector<__int128>(all.size()));
            for (int i = 0; i < all.size(); ++i) {
                for (int j = i; j < all.size(); ++j) {
                    if (all[i] > x[0] || all[j] < x[0]) {
                        continue;
                    }

                    ans[i][j] = t * std::min(std::abs(all[j] - x[0]), std::abs(all[i] - x[0])) * 2 + std::max(std::abs(all[j] - x[0]), std::abs(all[i] - x[0]));
                }
            }

            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < all.size(); ++j) {
                    for (int k = j; k < all.size(); ++k) {
                        if (all[j] > x[0] || all[k] < x[0]) {
                            continue;
                        }

                        __int128 f = (x[i] - x[0]) / d;

                        f = (f * d) + x[0];

                        ans[j][k] += std::min({(x[i] - std::max(all[j], std::min(f, all[k]))) * (x[i] - std::max(all[j], std::min(f, all[k]))), (x[i] - std::max(all[j], std::min(f - d, all[k]))) * (x[i] - std::max(all[j], std::min(all[k], f - d))), (x[i] - std::max(all[j], std::min(all[k], f + d))) * (x[i] - std::max(all[j], std::min(all[k], f + d)))});
                    }
                }
            }
            
            for (int i = 0; i < all.size(); ++i) {
                for (int j = i; j < all.size(); ++j) {
                    if (all[i] > x[0] || all[j] < x[0]) {
                        continue;
                    }
                    res = std::min(res, ans[i][j]);
                }
            }

            cout(res); std::cout << '\n';
        }
    } else {
        while (m--) {
            int _; std::cin >> _;
     
            __int128 res = 0;
            for (int i = 1; i <= n; ++i) {
                __int128 f = (x[i] - x[0]) / d;
     
                f = (f * d) + x[0];
     
                res += std::min({(x[i] - f) * (x[i] - f), (x[i] - f - d) * (x[i] - f - d), (x[i] - f + d) * (x[i] - f + d)});
            }
     
            cout(res); std::cout << '\n';
        }
    }
    return 0;
}
