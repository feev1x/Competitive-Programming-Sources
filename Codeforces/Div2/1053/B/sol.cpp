#include <bits/stdc++.h>

inline void solve() {
    int n, m; std::cin >> n >> m;

    std::string s; std::cin >> s;

    std::set<std::pair<int, int>> st;
    std::vector<int> a(m), add;

    int ls = 0;
    for (auto &u: a) {
        std::cin >> u;

        if (u - ls - 1 > 0) {
            st.emplace(ls + 1, u - 1);
        }

        ls = u;
    }

    ls = 1;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < m && ls >= a[j]) {
            j++;
        }

        if (s[i] == 'A') {
            add.emplace_back(++ls);
        } else {
            while (j < m && a[j] - std::max((j ? a[j - 1] : 0), ls) <= 1) {
                j++;
            }

            int pos;
            if (j == m) {
                pos = a.back() + 1;
            } else {
                pos = (j ? a[j - 1] : 0) + 1;
            }

            if (pos <= ls) {
                ls++;
            } else {
                ls = pos;
            }

            add.emplace_back(ls);

            while (j < m && a[j] - std::max((j ? a[j - 1] : 0), ls) <= 1) {
                j++;
            }

            if (j == m) {
                pos = a.back() + 1;
            } else {
                pos = (j ? a[j - 1] : 0) + 1;
            }

            if (pos <= ls) {
                ls++;
            } else {
                ls = pos;
            }
        }
    }

    for (auto u: add) {
        a.emplace_back(u);
    }

    std::sort(a.begin(), a.end());
    a.erase(std::unique(a.begin(), a.end()), a.end());

    std::cout << a.size() << '\n';
    for (auto u: a) {
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
