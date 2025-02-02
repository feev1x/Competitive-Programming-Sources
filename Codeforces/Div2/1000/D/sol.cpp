/**
 *    author:  feev1x
 *    created: 22.01.2025 18:32:15
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;
        
        int kmax = 0;
        for (int i = n, j = m; i > 0 && j > 0;) {
            if (i > j) {
                i -= 2;
                j--;
            } else {
                if (i == 1 && j == 1) {
                    break;
                }

                j -= 2;
                i--;
            }

            kmax++;
        }

        std::vector<int64_t> a(n), b(m);
        for (auto &u: a) {
            std::cin >> u;
        }

        for (auto &u: b) {
            std::cin >> u;
        }

        
    }
    return 0;
}
