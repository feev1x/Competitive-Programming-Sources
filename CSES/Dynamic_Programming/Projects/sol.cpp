/**
 *    author:  feev1x
 *    created: 27.02.2025 14:44:53
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    int64_t mx = 0;
    std::set<std::array<int, 3>> st;
    std::vector<int> a(n), b(n), p(n);
    std::vector<int64_t> ans(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i] >> p[i];

        st.insert({a[i], 0, i});
        st.insert({b[i], 1, i});
    }

    for (auto [pos, type, i]: st) {
        if (!type) {
            ans[i] = mx + p[i];
        } else {
            mx = std::max(mx, ans[i]);
        }
    }

    std::cout << *std::max_element(ans.begin(), ans.end()) << '\n';
    return 0;
}
