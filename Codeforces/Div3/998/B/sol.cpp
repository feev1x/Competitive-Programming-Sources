/**
 *    author:  feev1x
 *    created: 19.01.2025 20:43:29
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        bool flag = true;
        std::vector<std::pair<int, int>> res;
        for (int i = 0; i < n; ++i) {
            std::vector<int> a(m);

            int fs = -1;
            for (auto &u: a) {
                std::cin >> u;
                
                if (fs == -1) {
                    fs = u % n;
                }

                if (fs != u % n) {
                    flag = false;
                }
            }

            res.emplace_back(fs, i);
        }

        if (!flag) {
            std::cout << "-1\n";

            continue;
        }

        std::sort(res.begin(), res.end());

        for (int i = 0; i < n; ++i) {
            std::cout << res[i].second + 1 << " \n"[i == n - 1];
        }
    }
    return 0;
}
