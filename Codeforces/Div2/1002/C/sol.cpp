/**
 *    author:  feev1x
 *    created: 02.02.2025 21:03:56
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> b;
        std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                std::cin >> a[i][j];
            }

            for (int j = n; j >= 1; --j) {
                if (a[i][j] != 1) {
                    b.emplace_back(n - j);

                    break;
                } else if (j == 1) {
                    b.emplace_back(n);
                }
            }
        }

        std::sort(b.begin(), b.end());

        int res = 1;
        for (int i = 0, j = 0; i < n && j < n; ++i, ++j) {
            while (j < n && b[j] < i) {
                j++;
            }

            if (j < n) {
                res = i + 1;
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
