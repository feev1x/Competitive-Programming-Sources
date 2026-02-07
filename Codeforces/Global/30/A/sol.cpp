/**
 *    author:  feev1x
 *    created: 25.11.2025 13:41:18
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n);
        for (auto &u: a)
            std::cin >> u;

        int x; std::cin >> x;

        bool flag = *std::max_element(a.begin(), a.end()) >= x && *std::min_element(a.begin(), a.end()) <= x;
        std::cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}
