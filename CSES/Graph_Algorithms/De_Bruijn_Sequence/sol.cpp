/**
 *    author:  feev1x
 *    created: 04.03.2025 12:46:43
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    if (n == 1) {
        std::cout << "01\n";

        exit(0);
    }

    std::string res;
    std::vector<std::vector<int>> g(1 << n - 1);
    for (int u = 0; u < 1 << n - 1; ++u) {
        int v = (u << 1) % (1 << n - 1);

        g[u].emplace_back(v);
        g[u].emplace_back(v | 1);
    }

    std::stack<int> stk;

    stk.emplace(0);
    while (stk.size()) {
        int v = stk.top();

        if (g[v].empty()) {
            res += char((v & 1) + '0');
            stk.pop();
        } else {
            stk.emplace(g[v].back());
            g[v].pop_back();
        }
    }

    for (int i = 0; i < n - 2; ++i) {
        res += '0';
    }

    std::cout << res << '\n';
    return 0;
}
