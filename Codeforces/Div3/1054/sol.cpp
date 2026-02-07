#include <bits/stdc++.h>

inline void solve() {
    int n, q; std::cin >> n >> q;

    int sq = std::sqrt(n) + 1;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    {
        auto b = a;
        std::sort(b.begin(), b.end());
        b.erase(std::unique(b.begin(), b.end()), b.end());

        for (auto &u: a) {
            u = std::lower_bound(b.begin(), b.end(), u) - b.begin();
        }
    }

    std::vector<std::vector<int>> ans(q);

    std::vector<std::vector<std::array<int, 3>>> B(sq + 5);

    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r;

        B[l / sq].push_back(r, l, i);
    }

    int sqpos = 0;
    for (auto qq: B) {
        sqpos += sq;

        std::sort(qq.begin(), qq.end());

        std::vector<int> cnt(n);

        int nw = sqpos;
        for (auto [r, l, i]: qq) {
            if (r >= sqpos) {
                while (nw <= r) {
                    Add(nw++);
                }
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        std::sort(ans[i].begin(), ans[i].end());

        if (ans[i].size()) {
            for (auto u: ans[i]) {
                std::cout << u << ' ';
            }

            std::cout << '\n';
        } else {
            std::cout << "-1\n";
        }
    }
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
