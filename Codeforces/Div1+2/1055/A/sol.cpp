#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::set<int> st;
    while (n--) {
        int u; std::cin >> u;

        st.emplace(u);
    }

    std::cout << st.size() * 2 - 1 << '\n';
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
