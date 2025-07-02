/**
 *    author:  feev1x
 *    created: 15.06.2025 10:12:08
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int d, s; std::cin >> d >> s;

    if (s - d <= 1 && s != d || (s - d) % 2 == 1) {
        std::cout << "0\n";

        exit(0);
    }

    int dif = s - d;


    std::vector<int> dp(dif + 1, d + 5), p(dif + 1, -1);
    dp[dif] = 0;
    for (int i = dif; i >= 0; i -= 2) {
        for (int j = 2; i >= j * j - j && j <= 9; ++j) {
            if (dp[i - (j * j - j)] > dp[i] + j) {
                dp[i - (j * j - j)] = dp[i] + j;
                p[i - (j * j - j)] = j;
            }
        }
    }

    if (dp[0] > d) {
        std::cout << "0\n";

        exit(0);
    }

    for (int i = 0; i < d - dp[0]; ++i) {
        std::cout << 1;
    }

    for (int i = 0; i != dif; i += p[i] * p[i] - p[i]) {
        std::cout << p[i];
    }

    std::cout << '\n';
    return 0;
}
