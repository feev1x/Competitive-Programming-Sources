/**
 *    author:  feev1x
 *    created: 06.09.2025 18:06:41
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<std::string> s(n);
    std::vector<std::vector<int>> p(n + 1, std::vector<int>(n + 1));
    for (auto &u: s)
        std::cin >> u;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            p[i + 1][j + 1] = p[i][j + 1] + p[i + 1][j] - p[i][j] + (i + 1 < n && j + 1 < n && s[i][j] == '.' && s[i + 1][j] == '.'
                    && s[i][j + 1] == '.' && s[i + 1][j + 1] == '.');

    while (q--) {
        int u, d, l, r; std::cin >> u >> d >> l >> r;

        if (u == d || l == r) {
            std::cout << "0\n";
            continue;
        }

        d--, r--;
        u--, l--;
        std::cout << p[d][r] - p[d][l] - p[u][r] + p[u][l] << '\n';
    }

    return 0;
}
