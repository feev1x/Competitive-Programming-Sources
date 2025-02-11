/**
 *    author:  feev1x
 *    created: 10.02.2025 15:25:21
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> p(n + 1), q(n + 1), pos(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> p[i];
    }

    for (int i = 1; i <= n; ++i) {
        std::cin >> q[i];

        pos[q[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << q[p[pos[i]]] << " \n"[i == n];
    }
    return 0;
}
