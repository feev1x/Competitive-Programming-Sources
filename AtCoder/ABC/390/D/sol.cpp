/**
 *    author:  feev1x
 *    created: 29.01.2025 20:54:55
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }
    
    std::map<std::vector<int64_t>, bool> used;

    std::set<int64_t> res;

    auto b = a;

    auto Dfs = [&](auto &&self) {
        if (used[b]) {
            return;
        }

        used[b] = true;
        std::vector<int> pos;
        int xr = 0;
        for (int i = 0; i < n; ++i) {
            xr ^= b[i];

            if (b[i]) {
                pos.emplace_back(i);
            }
        }

        res.emplace(xr);

        for (int x = 0; x < pos.size(); ++x) {
            for (int y = x + 1; y < pos.size(); ++y) {
                int i = pos[x], j = pos[y];
                int temp = b[i];
                b[i] = 0;
                b[j] += temp;
                self(self);
                b[i] = temp;
                b[j] -= temp;
            }
        }
    };

    Dfs(Dfs);

    std::cout << res.size() << '\n';
    return 0;
}
