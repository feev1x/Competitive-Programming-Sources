/**
 *    author:  feev1x
 *    created: 21.04.2025 10:38:27
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::multiset<int> st;
    for (int i = 0; i < n; ++i) {
        int u; std::cin >> u;

        auto it = st.lower_bound(u);

        if (st.size() && it != st.begin()) {
            --it;
            st.erase(it);
        }

        st.emplace(u);
    }

    std::cout << st.size() << '\n';
    return 0;
}
