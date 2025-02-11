/**
 *    author:  feev1x
 *    created: 10.02.2025 15:18:06
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<bool> ap(n + 1);
    for (int i = 0; i < m; ++i) {
        int u; std::cin >> u;

        ap[u] = true;
    }

    std::vector<int> a;
    for (int i = 1; i <= n; ++i) {
        if (!ap[i]) {
            a.emplace_back(i);
        }
    }

    int sz = a.size();

    std::cout << sz << '\n';
    for (int i = 0; i < sz; ++i) {
        std::cout << a[i] << " \n"[i == sz - 1];
    }
    return 0;
}
