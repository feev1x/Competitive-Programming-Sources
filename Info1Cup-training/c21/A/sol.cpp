#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        pos[p[i]] = i;
    }

    std::set<int> st1, st2;
    for (int i = 1; i <= n / 2; ++i) {
        if (p[i] > n / 2) {
            st1.emplace(i);
        }
    }

    for (int i = n, j = 1; i > n / 2; --i, ++j) {
        if (p[i] <= n / 2) {
            st2.emplace(j);
        }
    }

    if (st1 != st2 || (int)st1.size() % 2 == 1) {
        std::cout << "-1\n";
        return;
    }

    std::vector<std::pair<int, int>> res;
    auto Swap = [&](int i, int j) {
        int x = n - i + 1, y = n - j + 1;

        res.emplace_back(i, j);
        std::swap(p[i], p[j]);
        std::swap(pos[p[i]], pos[p[j]]);
        std::swap(p[x], p[y]);
        std::swap(pos[p[x]], pos[p[y]]);
    };

    auto st = st1;

    while (st.size()) {
        int x = *st.begin();

        st.erase(st.begin());

        int y;
        if (st.find(p[n - x + 1]) == st.end() || x == p[n - x + 1]) {
            y = n - *st.begin() + 1;
            st.erase(st.begin());
        } else {
            y = n - p[n - x + 1] + 1;
            st.erase(p[n - x + 1]);
        }

        Swap(x, y);
    }

    for (int i = 1; i <= n / 2; ++i) {
        if (pos[i] != i) {
            Swap(i, pos[i]);
        }
    }

    if (is_sorted(p.begin(), p.end())) {
        std::cout << res.size() << ' ' << res.size() << '\n';

        for (auto [u, v]: res) {
            std::cout << u << ' ' << v << '\n';
        }
    } else {
        std::cout << "-1\n";
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
