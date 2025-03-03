/**
 *    author:  feev1x
 *    created: 15.02.2025 08:44:30
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::set<int> st;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    st.emplace(n);

    std::vector<std::pair<int, int>> b;
    for (int i = 0; i < n; ++i) {
        b.emplace_back(a[i], i);
    }


    std::sort(b.begin(), b.end(), std::greater<>());

    int res = 0;
    for (auto [u, i]: b) {
        res = std::max(res, *st.upper_bound(i) - i - 1);

        st.emplace(i);
    }

    std::cout << res << '\n';
    return 0;
}
