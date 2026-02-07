/**
 *    author:  feev1x
 *    created: 03.11.2025 13:46:43
**/
#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    std::vector<int> a(n);
    for (auto &u: a)
        std::cin >> u;

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v; --u, --v;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    int mx = 0, cnt = 0;
    for (int mask = 0; mask < 1 << n; ++mask) {
        bool flag = true; 
        
        int sum = 0;
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1) {
                for (auto to: g[i])
                    if (mask >> to & 1)
                        flag = false;

                sum += a[i];
            }

        if (!flag)
            continue;

        if (mx < sum)
            mx = sum, cnt = 1;
        else if (mx == sum)
            cnt++;
    }

    std::cout << mx << ' ' << cnt << '\n';
    return 0;
}
