#include <bits/stdc++.h>

inline void solve() {
    int n, k; std::cin >> n >> k;

    std::set<std::pair<int, int>> st;
    std::vector<int> a(n + 1), p(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        p[i] = p[i - 1] + a[i];

        st.emplace(a[i] - p[i - 1], i);
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
