#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<std::set<int>> st(2);
    std::vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];

        pos[p[i]] = i;
        st[p[i] % 2].emplace(i);
    }

    auto Do = [&](int i) {
        if (p[i] < 3) {
            return;
        }

        int j = pos[p[i] - 1], k = pos[p[i] - 2];

        pos[p[i]] = j;
        pos[p[i] - 1] = k;
        pos[p[i] - 2] = i;

        p[i] -= 2;

        st[p[j] % 2].erase(j);
        st[p[k] % 2].erase(k);
        p[j]++, p[k]++;
        st[p[j] % 2].emplace(j);
        st[p[k] % 2].emplace(k);
    };

    for (int i = 1; i <= n; ++i) {
        int j = *st[i % 2].begin();

        while (p[j] > i) {
            Do(j);
        }

        st[i % 2].erase(j);
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << p[i] << " \n"[i == n];
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
