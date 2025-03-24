/**
 *    author:  feev1x
 *    created: 20.03.2025 11:48:54
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::sort(a.begin(), a.end());

    std::multiset<int> st{0};
    std::vector<std::vector<int>> del(n + 1);
    while (m--) {
        int b, c; std::cin >> b >> c;

        st.emplace(c);
        del[b].emplace_back(c);
    }

    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        for (auto u: del[i]) {
            st.erase(st.find(u));
        }

        sum += std::max(a[i], *st.rbegin());
    }

    std::cout << sum << '\n';
    return 0;
}
