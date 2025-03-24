/**
 *    author:  feev1x
 *    created: 15.03.2025 18:06:45
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::map<int, int> mp1, mp2;
    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;

        mp2[u]++;
    }

    int res = 0;
    for (int i = 0; i + 1 < n; ++i) {
        mp1[a[i]]++;
        mp2[a[i]]--;

        if (!mp2[a[i]]) {
            mp2.erase(a[i]);
        }
        
        res = std::max(res, (int)mp1.size() + (int)mp2.size());
    }

    std::cout << res << '\n';
    return 0;
}
