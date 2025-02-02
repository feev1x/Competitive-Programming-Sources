/**
 *    author:  feev1x
 *    created: 01.02.2025 18:13:16
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n + 1), t(m + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> s[i];

        s[i] = " " + s[i];
    }

    for (int i = 1; i <= m; ++i) {
        std::cin >> t[i];

        t[i] = " " + t[i];
    }

    for (int a = 1; a <= n - m + 1; ++a) {
        for (int b = 1; b <= n - m + 1; ++b) {
            bool flag = true;

            for (int i = 1; i <= m && flag; ++i) {
                for (int j = 1; j <= m && flag; ++j) {
                    if (s[a + i - 1][b + j - 1] != t[i][j]) {
                        flag = false;

                        break;
                    }
                }
            }

            if (flag) {
                std::cout << a << ' ' << b << '\n';

                exit(0);
            }
        }
    }

    std::cout << "-1\n";
    return 0;
}
