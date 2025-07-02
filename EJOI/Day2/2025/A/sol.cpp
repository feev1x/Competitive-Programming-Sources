/**
 *    author:  feev1x
 *    created: 28.04.2025 09:26:20
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> p(n + 1), b(n + 1), a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    if (*std::max_element(p.begin(), p.end()) == 1) {
        int l = 0, r = n - 1, ans = -1;

        while (l <= r) {
            int m = l + r >> 1;

            int cnt = 0;
            for (int i = 1; i <= m; ++i) {
                if (
            }
        }
    } else {
    }
    return 0;
}
