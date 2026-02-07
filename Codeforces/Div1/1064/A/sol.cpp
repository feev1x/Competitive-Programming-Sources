/**
 *    author:  feev1x
 *    created: 16.11.2025 20:37:03
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n), next(n), prev(n);
        std::set<std::pair<int, int>> st;
        for (auto &u: a)
            std::cin >> u;

        for (int i = 0; i < n; ++i)
            next[i] = (i + 1) % n, prev[i] = (i - 1 + n) % n, st.emplace(a[i], i);
        
        int64_t res = 0;
        while (st.size() > 1) {
            auto [val, pos] = *st.begin();

            st.erase(st.begin());

            if (a[next[pos]] > a[prev[pos]]) {
                res += a[prev[pos]];

                prev[next[pos]] = prev[pos];
                next[prev[pos]] = next[pos];
            } else {
                res += a[next[pos]];

                prev[next[pos]] = prev[pos];
                next[prev[pos]] = next[pos];
            }
        }

        std::cout << res << '\n';
    }
    return 0;
}
