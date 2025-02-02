/**
 *    author:  feev1x
 *    created: 29.01.2025 20:43:39
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (auto &u: s) {
        std::cin >> u;
    }

    int a = n, b = -1, c = m, d = -1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '#') {
                a = std::min(a, i);
                b = std::max(b, i);
                c = std::min(c, j);
                d = std::max(d, j);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a <= i && i <= b && c <= j && j <= d) {
                if (s[i][j] == '.') {
                    std::cout << "No\n";

                    exit(0);
                }
            }
        }
    }

    std::cout << "Yes\n";
    return 0;
}
