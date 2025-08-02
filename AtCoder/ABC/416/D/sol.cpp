/**
 *    author:  feev1x
 *    created: 26.07.2025 18:27:18
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<int> a(n), b(n);
        std::multiset<int> st;

        int64_t sum = 0;
        for (auto &u: a)
            std::cin >> u, st.emplace(u), sum += u;

        for (auto &u: b)
            std::cin >> u, sum += u;

        std::sort(b.begin(), b.end(), std::greater<>());
        for (auto u: b) {
            auto it = st.lower_bound(m - u);

            if (st.empty() || it == st.end())
                break;

            sum -= m;

            st.erase(it);
        }

        std::cout << sum << '\n';
    }

    return 0;
}
