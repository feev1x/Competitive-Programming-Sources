/**
 *    author:  feev1x
 *    created: 06.03.2025 14:18:54
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::vector<int> a(n), b(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        for (auto &u: b) {
            std::cin >> u;
        }

        std::sort(b.begin(), b.end());

        std::vector<std::pair<int, int>> ap;
        for (int i = 0; i < n; ++i) {
            ap.emplace_back(a[i], i);
        }

        std::sort(ap.begin(), ap.end());
        
        std::vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[ap[i].second] = b[i];
        }

        for (int i = 0; i < n; ++i) {
            std::cout << res[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}
