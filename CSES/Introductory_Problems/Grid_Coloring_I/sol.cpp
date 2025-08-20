/**
 *    author:  feev1x
 *    created: 19.08.2025 15:43:30
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
    
    int dx[]{0, -1, 0};
    int dy[]{0, 0, -1};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            for (int k = 0; k < 4; ++k) {
                bool flag = true;

                for (int l = 0; l < 3; ++l) {
                    int x = dx[l] + i, y = dy[l] + j;

                    if (x >= 0 && x < n && y >= 0 && y < m && k == s[x][y] - 'A')
                        flag = false;
                }

                if (flag) {
                    std::cout << (s[i][j] = char(k + 'A')) << (j == m - 1 ? "\n" : "");
                    break;
                }
            }
    return 0;
}
