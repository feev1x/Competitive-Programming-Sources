#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    int m = 2998;
    std::vector<int> res;
    for (int i = 0; i < m; ++i) {
        int l = n * i, r = l + i - 1;
        
        for (int j = l; j <= l; ++j) {
            if (j < 1e8 || j >= 1e9) {
                continue;
            }

            int sum = j / 1000000 + j / 1000 % 1000 + j % 1000;

            if (sum != i) {
                continue;
            }

            res.emplace_back(j);
        }
    }

    std::cout << res.size() << '\n';
    for (auto u: res) {
        std::cout << u << '\n';
    }
    return 0;
}
