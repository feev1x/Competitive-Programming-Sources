/**
 *    author:  feev1x
 *    created: 25.11.2025 14:39:58
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
        
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<int> a(n), b(m), c(m);
        for (auto &u: a)
            std::cin >> u;

        for (auto &u: b)
            std::cin >> u;

        for (auto &u: c)
            std::cin >> u;

        
        std::multiset<int> st;
        for (int i = 0; i < n; ++i)
            st.emplace(a[i]);

        std::vector<int> idx(m);

        std::iota(idx.begin(), idx.end(), 0);

        std::sort(idx.begin(), idx.end(), [&](int i, int j) {
            if (!!c[i] == !!c[j])
                return b[i] < b[j];

            return c[i] > c[j];
        });

        int cnt = 0;
        for (auto i: idx) {
            if (c[i]) {
                auto it = st.lower_bound(b[i]);

                if (st.size() && it != st.end()) {
                    cnt++;

                    int vl = std::max(c[i], *it);
                    st.erase(it);
                    st.emplace(vl);
                }
            } else {
                auto it = st.lower_bound(b[i]);

                if (st.size() && it != st.end()) {
                    cnt++;
                    st.erase(it);
                }
            }
        }

        std::cout << cnt << '\n';
    }
    return 0;
}
