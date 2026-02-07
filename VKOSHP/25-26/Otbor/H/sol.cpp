#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;


        std::vector<int> a(n);

        std::map<int, bool> mp;
        for (auto &u: a) {
            std::cin >> u;

            mp[u] = !mp[u];
        }

        if (n & 1) {
            std::cout << (1 << 30) - 1 << '\n';
            continue;
        }

        int64_t res = -1;
        for (auto [key, val]: mp)
            if (val) {
                res = key;
                break;
            }

        std::cout << res << '\n';
    }
}
