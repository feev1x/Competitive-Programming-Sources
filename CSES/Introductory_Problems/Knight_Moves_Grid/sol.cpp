/**
 *    author:  feev1x
 *    created: 19.08.2025 15:37:32
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

constexpr int INF = 1e9;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector dis(n, std::vector<int>(n, INF));

    int dx[]{1, 1, -1, -1, 2, 2, -2, -2};
    int dy[]{2, -2, 2, -2, 1, -1, -1, 1};

    std::queue<std::pair<int, int>> q;

    dis[0][0] = 0;
    q.emplace(0, 0);
    while (q.size()) {
        auto [i, j] = q.front();

        q.pop();
        for (int k = 0; k < 8; ++k) {
            int x = dx[k] + i, y = dy[k] + j;

            if (x >= 0 && x < n && y >= 0 && y < n && dis[x][y] > dis[i][j] + 1) {
                dis[x][y] = dis[i][j] + 1;

                q.emplace(x, y);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            std::cout << dis[i][j] << " \n"[j == n - 1];
    return 0;
}
