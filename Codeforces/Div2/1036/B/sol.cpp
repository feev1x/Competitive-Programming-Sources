/**
 *    author:  feev1x
 *    created: 06.07.2025 20:40:52
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n);
        for (auto &u: a) {
            std::cin >> u;
        }

        std::cout << std::min({a[0] + a[1], a[0] + a[0]}) << '\n';
    }

    return 0;
}
