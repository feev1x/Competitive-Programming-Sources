/**
 *    author:  feev1x
 *    created: 02.02.2025 11:38:27
**/
#include <bits/stdc++.h>

constexpr int INF = 2e9;

inline int max(int a, int b) {
    if (a > b) {
        return a;
    }

    return b;
}

inline int min(int a, int b) {
    if (a < b) {
        return a;
    }

    return b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    srand(time(nullptr));
    
    int n; std::cin >> n;

    int mn1 = INF, mn2 = INF;
    std::vector<int> t(n), a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i] >> a[i] >> b[i];

        if (a[i]) {
            mn1 = min(mn1, t[i] / a[i]);
        }
        if (b[i]) {
            mn2 = min(mn2, t[i] / b[i]);
        }
    }

    int res1 = INF, res2 = INF;
    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            res1 = min(res1, (t[i] - a[i] * mn1) / b[i] + mn1);
        }

        if (a[i]) {
            res2 = min(res2, (t[i] - b[i] * mn2) / a[i] + mn2);
        }
    }

    int res = max(res1, res2);

    if (res1 != res2) {
        assert(std::abs(res1 - res2) == 1);

        std::cout << res << '\n';

        exit(0);
    }


    for (int i = 0; i < n; ++i) {
        if (b[i]) {
            if (res == (t[i] - a[i] * mn1) / b[i] + mn1 && (t[i] - a[i] * mn1) % b[i] == 0) {
                std::cout << res << '\n';

                exit(0);
            }
        }

        if (a[i]) {
            if (res == (t[i] - b[i] * mn1) / a[i] + mn1 && (t[i] - b[i] * mn1) % a[i] == 0) {
                std::cout << res << '\n';

                exit(0);
            }
        }
    }

    std::cout << res + 1 << '\n';
    return 0;
}
