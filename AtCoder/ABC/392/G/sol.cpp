/**
 *    author:  feev1x
 *    created: 11.02.2025 11:41:03
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> s(n);
    for (auto &u: s) {
        std::cin >> u;
    }

    std::sort(s.begin(), s.end());

    int l = 0, r = 2, res = 0;
    for (int i = 1; i + 1 < n; ++i) {
        
    }

    std::cout << res << '\n';
    return 0;
}
