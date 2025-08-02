/**
 *    author:  feev1x
 *    created: 27.07.2025 20:36:11
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, c; std::cin >> n >> c;

        std::vector<int64_t> a(n);
        for (auto &u: a)
            std::cin >> u;

        std::sort(a.begin(), a.end(), std::greater<>());
        int64_t mul = 1, res = 0;
        for (auto u: a)
            if (u * mul > c)
                res++;
            else
                mul *= 2;

        std::cout << res << '\n';
    }
    return 0;
}
