#include <bits/stdc++.h>

inline void solve() {
    int n; int64_t k; std::cin >> n >> k;
    
    std::multiset<int64_t> st;
    std::vector<int64_t> q(n), r(n);
    for (auto &u: q) {
        std::cin >> u;

        st.emplace(u);
    }

    for (auto &u: r) {
        std::cin >> u;
    }

    std::sort(r.begin(), r.end());

    int res = 0;
    for (auto u: r) {
        int64_t val = (k - u) / (u + 1);

        auto it = st.upper_bound(val);

        if (st.empty() || it == st.begin()) {
            continue;
        }

        --it;

        assert((*it) * (u + 1) + u <= k);
        res++;

        st.erase(it);
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
