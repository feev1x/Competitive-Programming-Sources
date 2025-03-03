/**
 *    author:  feev1x
 *    created: 20.02.2025 15:42:29
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    int res = 0;
    std::map<int, std::map<int, bool>> mp;
    for (int i = 0; i < m; ++i) {
        int u, v; std::cin >> u >> v;
        
        if (u > v) {
            std::swap(u, v);
        }

        if (mp[u][v] || u == v) {
            res++;

            continue;
        }

        mp[u][v] = true;
    }
    
    std::cout << res << '\n';
    return 0;
}
