/**
 *    author:  feev1x
 *    created: 22.01.2025 18:09:46
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, l, r; std::cin >> n >> l >> r; l--, r--;

        std::vector<int64_t> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        std::sort(a.begin(), a.begin() + l);
        std::sort(a.begin() + l, a.begin() + r + 1);
        std::sort(a.begin() + r + 1, a.end());

        int64_t min1 = 0, min2 = 0;
        for (int i = r, j = 0; i >= l; --i, ++j) {
            if (j < l && a[i] > a[j]) {
                min1 += a[j];
            } else {
                min1 += a[i];
            }
        }

        for (int i = r, j = r + 1; i >= l; --i, ++j) {
            if (j < n && a[i] > a[j]) {
                min2 += a[j];
            } else {
                min2 += a[i];
            }
        }

        std::cout << std::min(min1, min2) << '\n';
    }
    return 0;
}
