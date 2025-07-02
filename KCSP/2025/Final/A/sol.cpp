/**
 *    author:  feev1x
 *    created: 15.06.2025 12:55:49
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long double n, p, S; std::cin >> n >> p >> S;    
    std::swap(n, p);

    std::vector<std::array<long double, 3>> c((int)n + 1);
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < n; ++j) {
            long double c1, c2, c3; std::cin >> c1 >> c2 >> c3;

            c[j + 1][0] = std::max(c[j + 1][0], c1);
            c[j + 1][1] = std::max(c[j + 1][1], c2);
            c[j + 1][2] = std::max(c[j + 1][2], c3);
        }
    }

    long double l = 0, r = 1e4, ans = 0;
    for (int _ = 0; _ < 1000; ++_) {
        long double m = (l + r) / 2;
    
        bool flag = false;
        for (int i = 1; i <= n; ++i) {
            long double c1 = (m + S);
            long double c2 = (m + S);
            long double c3 = (m + S);


            if (c1 * c[i][1] * c[i][2] + c2 * c[i][0] * c[i][2] + c3 * c[i][0] * c[i][1] <= S * c[i][0] * c[i][1] * c[i][2]) {
                flag = true;

                break;
            }
        }


        if (flag) {
            l = m + 1e-6, ans = m;
        } else {
            r = m - 1e-6;
        }
    }

    std::cout << std::fixed << std::setprecision(6) << ans << '\n';
    return 0;
}
