/**
 *    author:  feev1x
 *    created: 06.07.2025 08:45:18
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));

    int pl = n, pr = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j)
            std::cin >> a[i][j];
        
        if (i == 1) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] == a[i].back()) {
                    pr = j;

                    break;
                }
            }
        } else {
            if (pl == n && a[i].back() != a[i - 1].back()) {
                pl = i - 1;
            }
        }
    }

    std::vector<int> res{pl};
    for (int i = pl + 1; i < pr; ++i) {
        if (a[i][i] != a[i - 1][i]) {
            if (res.back() == i - 1) {
                res.emplace_back(i);
            }

            continue;
        }

        if (a[pl][i] != a[pl + 1][i]) {
            if (a[pl][i] != a[pl][i - 1]) {
                res.emplace_back(i);
            }

            continue;
        }

        if (a[i][pr] != a[i][pr - 1]) {
            if (a[i][pr] != a[i + 1][pr]) {
                res.emplace_back(i);
            }

            continue;
        }

        if (a[pl][i] != a[pl][i - 1]) {
            continue;
        }

        if (a[i][pr] != a[i + 1][pr]) {
            continue;
        }

        if (i - 1 == pl || a[pl + 1][i - 1] != a[pl][i]) {
            continue;
        }

        if (i + 1 == pr || a[i + 1][pr - 1] != a[i][pr]) {
            continue;
        }

        res.emplace_back(i);
    }

    std::sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i];

        if (i + 1 < res.size()) {
            std::cout << ' ';
        }
    }

    if (pr != pl)
        std::cout << ' ' << pr;
    return 0;
}
