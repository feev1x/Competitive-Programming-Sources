/**
 *    author:  feev1x
 *    created: 29.07.2025 00:14:25
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::queue<std::tuple<std::vector<std::vector<short>>, int, int, int>> q;

        std::vector<std::vector<short>> st(n, std::vector<short>(m));

        int cn = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int u; std::cin >> u;

                st[i][j] = u;
                cn += !st[i][j];
            }

        std::map<std::tuple<std::vector<std::vector<short>>, int, int>, short> mp;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (!st[i][j]) {
                    st[i][j] = 2;

                    mp[{st, i, j}] = true;
                    q.emplace(st, i, j, cn - 1);

                    st[i][j] = 0;
                }

        int dx[]{1, -1, 0, 0};
        int dy[]{0, 0, 1, -1};

        bool flag = false;
        while (q.size()) {
            auto [a, x, y, cnt] = q.front();

            if (!cnt) {
                bool fl = false;

                for (int k = 0; k < 4; ++k) {
                    int i = x + dx[k], j = y + dy[k];

                    if (i < n && i >= 0 && j < m && j >= 0 && a[i][j] == 2) {
                        fl = true;

                        break;
                    }
                }

                if (fl) {
                    std::cout << "Yes\n";
                    flag = true;
                    break;
                }
            }

            q.pop();
            for (int k = 0; k < 4; ++k) {
                int i = x + dx[k], j = y + dy[k];

                if (i < n && i >= 0 && j < m && j >= 0 && !a[i][j]) {
                    a[i][j] = true;

                    if (!mp[{a, i, j}])
                        q.emplace(a, i, j, cnt - 1), mp[{a, i, j}] = true;

                    a[i][j] = false;
                }
            }
        }

        if (!flag)
            std::cout << "No\n";
    }
    return 0;
}
