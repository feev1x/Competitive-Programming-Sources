/**
 *    author:  feev1x
 *    created: 07.09.2025 10:13:44
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
    
    int n, m; std::cin >> n >> m;

    std::vector<std::string> s(n);
    for (auto &u: s)
        std::cin >> u;

    int dx[]{1, -1, 0, 0};
    int dy[]{0, 0, 1, -1};

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == '.')
                continue;

            int cnt = 0;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];

                if (x >= 0 && y >= 0 && x < n && y < m && s[x][y] == '#')
                    cnt++;
            }

            if (cnt != 2 && cnt != 4) {
                std::cout << "No\n";
                exit(0);
            }
        }

    std::cout << "Yes\n";
    return 0;
}
