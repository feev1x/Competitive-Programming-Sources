/**
 *    author:  feev1x
 *    created: 02.02.2025 20:36:24
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n), b(n);
        std::set<int> st1, st2;
        for (auto &u: a) {
            std::cin >> u;

            st1.emplace(u);
        }

        for (auto &u: b) {
            std::cin >> u;

            st2.emplace(u);
        }

        if (st1.size() + st2.size() > 3) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
