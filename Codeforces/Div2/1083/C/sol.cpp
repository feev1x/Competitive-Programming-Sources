#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    int mx = 0;
    std::vector<std::vector<int>> a(n);
    for (int i = 0; i < n; ++i) {
        int l; std::cin >> l;

        a[i].resize(l);
        std::map<int, int> used;
        for (auto &u: a[i]) {
            std::cin >> u;

            mx = std::max(mx, u);
        }

        std::reverse(a[i].begin(), a[i].end());
        std::vector<int> nw;
        for (int j = 0; j < l; ++j) {
            if (!used[a[i][j]]) {
                used[a[i][j]] = true;
                nw.emplace_back(a[i][j]);
            }
        }

        a[i] = nw;
    }

    std::vector<bool> used(mx + 1);
    std::vector<int> res;
    while (a.size()) {
        std::sort(a.begin(), a.end(), std::greater<>());
        
        for (auto u: a.back()) {
            res.emplace_back(u);
            used[u] = true;
        }

        a.pop_back();

        for (auto &v: a) {
            std::vector<int> nw;

            for (auto u: v) {
                if (!used[u]) {
                    nw.emplace_back(u);
                }
            }

            v = nw;
        }
    }

    for (auto u: res) {
        std::cout << u << ' ';
    }
    
    std::cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;

    while (tt--) {
        solve();
    }

    return 0;
}
