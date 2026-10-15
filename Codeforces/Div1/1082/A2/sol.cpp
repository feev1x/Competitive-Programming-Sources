#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::vector<int> a(n);

    int64_t cnt = 0, idx = 1;

    std::map<int, int> mp;
    std::set<std::pair<int, int>> st;
    for (auto &u: a) {
        std::cin >> u;

        while (mp.size() && mp.rbegin()->first > u) {
            auto [val, i] = *mp.rbegin();
            st.erase({i, val});
            mp.erase(--mp.end());
        }

        if (st.empty() || u - st.rbegin()->second > 1 || !mp[u - 1]) {
            cnt += (n - idx + 1) * idx;

            mp.clear();
            st.clear();
        } else {
            cnt += (idx - mp[u - 1]) * (n - idx + 1);
        }

        mp[u] = idx;
        st.emplace(idx, u);

        idx++;
    }

    std::cout << cnt << '\n';
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
