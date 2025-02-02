/**
 *    author:  feev1x
 *    created: 26.01.2025 11:44:15
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int64_t> a(n);
    std::multiset<int64_t> st;
    for (auto &u: a) {
        std::cin >> u;

        st.emplace(u);
    }
    
    int64_t res = 0;
    for (auto u: a) {
        st.erase(st.find(u));

        if (st.size() && *--st.end() > u) {
            res += *--st.end() - u;
        }
    }

    std::cout << res << '\n';
    return 0;
}
