#include <bits/stdc++.h>

inline void solve() {
    int n; std::cin >> n;

    std::multiset<int> st;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        st.emplace(u);
    }

    int res = 0;
    for (int i = n - 1; i > 0; --i) {
        st.erase(st.find(a[i]));

        if (*st.rbegin() > a[i]) {
            res++;
        }
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
