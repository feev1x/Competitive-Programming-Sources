#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k; std::cin >> n >> k;
    std::vector<int> s(k);
    for (auto &u: s) {
        std::cin >> u;
    }
    int nw = 0;
    std::set<int> st;
    st.emplace(1);
    while (true) {
        int v = *st.begin();
        if (nw == n) {
            std::cout << v << '\n';
            return 0;
        }
        nw++;
        st.erase(st.begin());
        for (auto u: s) {
            st.emplace(v * u);
        }
    }
    return 0;
}
