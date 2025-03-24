/**
 *    author:  feev1x
 *    created: 06.03.2025 14:01:00
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> p(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i) {
            std::cin >> p[i];

            pos[p[i]] = i;
        }
        
        if (n == 1) {
            std::cout << "1\n";

            continue;
        }

        std::vector<int> res(n + 1);
        int tar = n;

        if (p[1] == n) {
            tar--;
        }

        for (int i = pos[tar] - 1; i >= 1; --i) {
            std::vector<int> new_res(1);

            for (int j = pos[tar]; j <= n; ++j) {
                new_res.emplace_back(p[j]);
            }

            for (int j = pos[tar] - 1; j >= i; --j) {
                new_res.emplace_back(p[j]);
            }

            for (int j = 1; j < i; ++j) {
                new_res.emplace_back(p[j]);
            }

            if (new_res > res) {
                res = new_res;
            }
        }

        if (pos[tar] == n) {
            std::vector<int> new_res(1);

            new_res.emplace_back(tar);

            for (int i = 1; i < n; ++i) {
                new_res.emplace_back(p[i]);
            }

            if (new_res > res) {
                res = new_res;
            }
        }

        for (int i = 1; i <= n; ++i) {
            std::cout << res[i] << " \n"[i == n];
        }
    }
    return 0;
}
