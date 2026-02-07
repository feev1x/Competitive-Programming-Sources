#include <bits/stdc++.h>

inline void solve() {
    int n, m, k; std::cin >> n >> m >> k;

    std::vector<int> a(n), b(m);
    for (auto &u: a) {
        std::cin >> u;
    }

    for (auto &u: b) {
        std::cin >> u;
    }

    std::sort(b.begin(), b.end());

    std::map<int, std::set<int>> mp;

    int nw = 0;
    for (auto u: a) {
        int i = std::upper_bound(b.begin(), b.end(), u) - b.begin();

        if (b.size() > i) {
            mp[b[i] - u].emplace(nw);
        }

        if (i) {
            mp[b[i - 1] - u].emplace(nw);
        }

        nw++;
    }

    std::set<int> st;
    for (int i = 0; i < n; ++i) {
        st.emplace(i);
    }

    std::string s; std::cin >> s;

    nw = 0;
    for (auto u: s) {
        nw += (u == 'L' ? -1 : 1);

        for (auto val: mp[nw]) {
            st.erase(val);
        }

        std::set<int>().swap(mp[nw]);

        std::cout << st.size() << ' ';
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
