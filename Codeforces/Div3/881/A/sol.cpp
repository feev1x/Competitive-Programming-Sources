/**
 *    author:  feev1x
 *    created: 30.06.2025 23:03:12
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        std::sort(a.begin(), a.end());

        int res = 0;
        for (int i = 0, j = n - 1; i < j; ++i, --j) {
            res += a[j] - a[i];
        }

        std::cout << res << '\n';
    }
    return 0;
}
