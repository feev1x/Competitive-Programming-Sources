/**
 *    author:  feev1x
 *    created: 09.04.2025 17:17:59
**/
#include <bits/stdc++.h>

constexpr long double EPS = 1e-10;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    int m; std::cin >> m;

    std::vector<int> b(m);
    for (auto &u: b) {
        std::cin >> u;
    }

    long double l = 0, r = 1e10, ans = -1;
    while (r - l >= EPS) {
        long double _m = (l + r) / 2;

        int j = 0;
        long double sum = 0;
        for (int i = 0; i < m && j < n; ++i) {
            if (b[i] > a[j] || (sum + b[i]) / a[j] > _m) {
                j++;

                sum = 0;
                i--;
            } else {
                sum += b[i];
            }
        }

        if (j < n) {
            r = _m - EPS;
            ans = _m;
        } else {
            l = _m + EPS;
        }
    }

    std::cout << std::fixed << std::setprecision(10);
    if (ans == -1) {
        std::cout << "-1\n";
    } else {
        std::cout << ans << '\n';
    }
    return 0;
}
