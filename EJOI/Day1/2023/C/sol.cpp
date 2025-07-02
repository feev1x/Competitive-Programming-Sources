/**
 *    author:  feev1x
 *    created: 01.05.2025 15:27:44
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, t; std::cin >> n >> m >> t;

    std::string s; std::cin >> s;

    std::swap(n, m);

    int res = 0;
    if (t == 2) {
        res = n * (n - 1) / 2;
    }

    if (t == 3) {
        res = n * (n - 1) * (n - 2) / 6;
    }

    if (t == 1) {
        res = 1;

        for (int i = 0; i < n; ++i) {
            res *= 2;
            res %= MOD;
        }

        res -= (n + 1);
    }

    std::cout << res << '\n';
    return 0;
}
