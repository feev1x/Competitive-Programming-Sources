/**
 *    author:  feev1x
 *    created: 26.01.2025 11:38:59
**/
#include <bits/stdc++.h>

constexpr int N = 1e5, INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> a(4);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());

    int res = INF;
    for (int mask = 0; mask < (1 << 4); ++mask) {
        int l = 0, r = 0;
        
        for (int i = 0; i < 4; ++i) {
            if (mask >> i & 1) {
                l += a[i];
            } else {
                r += a[i];
            }
        }

        res = std::min(res, std::abs(l - r));
    }

    std::cout << res << '\n';
    return 0;
}
