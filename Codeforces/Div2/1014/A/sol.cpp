/**
 *    author:  feev1x
 *    created: 29.03.2025 20:40:05
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

        std::sort(a.begin(), a.end());

        std::cout << a.back() - a.front() << '\n';
    }
    return 0;
}
