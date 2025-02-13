/**
 *    author:  feev1x
 *    created: 12.02.2025 11:57:47
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;    

    std::vector<int> p(n);
    for (auto &u: p) {
        std::cin >> u;
    }

    std::sort(p.begin(), p.end());


    return 0;
}
