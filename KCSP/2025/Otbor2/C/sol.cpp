/**
 *    author:  feev1x
 *    created: 02.02.2025 11:20:24
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> p(n);
    for (auto &u: p) {
        std::cin >> u;
    }

    auto p1 = p;

    std::sort(p.begin(), p.end());

    int m; std::cin >> m;
    while (m--) {
        int s; std::cin >> s;

        s = p1[s - 1];

        std::cout << std::upper_bound(p.begin(), p.end(), s) - p.begin() << " \n"[!m];
    }
    return 0;
}
