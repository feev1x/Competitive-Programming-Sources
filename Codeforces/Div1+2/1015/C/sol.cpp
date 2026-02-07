#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n + 1), b(n + 1), pa(n + 1), pb(n + 1), idx(n + 1);
    std::vector<std::pair<int, int>> res;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        pa[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];

        pb[b[i]] = i;
    }

    auto Swap = [&](int i, int j) {
        if (i != j) {
            res.emplace_back(i, j);
            std::swap(pa[a[i]], pa[a[j]]);
            std::swap(a[i], a[j]);
            std::swap(pb[b[i]], pb[b[j]]);
            std::swap(b[i], b[j]);
        }
    };

    bool flag = true;
    int mid = (n + 1) / 2;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == b[i]) {
            Swap(i, mid);
            continue;
        }

        if (pa[b[i]] != pb[a[i]]) {
            flag = false;
            break;
        }

        if (i == mid) {
            Swap(i, n - pa[b[i]] + 1);
        } else {
            Swap(n - i + 1, pa[b[i]]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[n - i + 1]) {
            flag = false;
            break;
        }
    }

    if (!flag) { 
        std::cout << "-1\n";
        return;
    }

    std::cout << res.size() << '\n';
    for (auto [u, v]: res) {
        std::cout << u << ' ' << v << '\n';
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
