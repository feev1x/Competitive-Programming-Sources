#include <bits/stdc++.h>

inline void solve() {
    int n, m; int64_t k; std::cin >> n >> m >> k;

    std::vector<int> a(m), x(n), y(n), z(n), val(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::set<std::pair<int, int>> st;
    std::vector<int> idx(n);
    std::vector<bool> used(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i] >> y[i] >> z[i];

        idx[i] = i;

        k -= y[i];
    }

    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return x[i] < x[j];
    });


    int res = 0;
    std::sort(a.begin(), a.end());
    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && x[idx[j]] <= a[i]) {
            st.emplace(z[idx[j]] - y[idx[j]], idx[j]);
            j++;
        }

        if (st.empty()) {
            continue;
        }

        res++;
        used[(--st.end())->second] = true;
        st.erase(--st.end());
    }

    std::sort(idx.begin(), idx.end(), [&](int i, int j) {
        return z[i] - y[i] < z[j] - y[j];
    });

    for (auto i: idx) {
        if (used[i] || k < z[i] - y[i]) {
            continue;
        }

        k -= (z[i] - y[i]);

        res++;
    }

    std::cout << res << '\n';
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
