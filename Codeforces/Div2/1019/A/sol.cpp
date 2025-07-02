/**
 *    author:  feev1x
 *    created: 21.04.2025 20:36:15
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::set<int> st;
        for (int i = 0; i < n; ++i) {
            int u; std::cin >> u;

            st.emplace(u);
        }

        std::cout << st.size() << '\n';
    }
    return 0;
}
