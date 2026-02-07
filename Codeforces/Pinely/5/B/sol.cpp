/**
 *    author:  feev1x
 *    created: 30.10.2025 22:38:40
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
        int n; std::cin >> n;

        std::vector<std::string> s(n);
        for (int i = 0; i < n; ++i)
            std::cin >> s[i];

        int x = n + 1, y = n + 1, x1 = n + 1, y1 = n + 1;

        bool flag = true;
        for (int i = 0; i + 2 < n; ++i)
            for (int j = 0; j < n; ++j)
                if (s[i][j] == '#' && s[i + 1][j] == '#' && s[i + 2][j] == '#')
                    flag = false;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j + 2 < n; ++j)
                if (s[i][j] == '#' && s[i][j + 1] == '#' && s[i][j + 2] == '#')
                    flag = false;

        
        if (!flag) {
            std::cout << "NO\n";
            continue;
        }

        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (s[i][j] == '#') {
                    cnt++;

                    if (j < y)
                        x = i, y = j;
                    else if (y == j && x > i)
                        x = i, y = j;

                    if (j < y1)
                        x1 = i, y1 = j;
                    else if (y1 == j && x1 < i)
                        x1 = i, y1 = j;
                }

        if (x == n + 1) {
            std::cout << "YES\n";
            continue;
        }

        {
            int i = x, j = y, cn = 0;

            bool flag = true;
            while (i < n && j < n) {
                cn += (s[i][j] == '#');

                if (flag)
                    i++;
                else
                    j++;

                flag = !flag;
            }

            if (cn == cnt) {
                std::cout << "YES\n";
                continue;
            }
        }

        {
            int i = x, j = y, cn = 0;

            bool flag = false;
            while (i < n && j < n) {
                cn += (s[i][j] == '#');

                if (flag)
                    i++;
                else
                    j++;

                flag = !flag;
            }

            if (cn == cnt) {
                std::cout << "YES\n";
                continue;
            }
        }

        {
            int i = x1, j = y1, cn = 0;

            bool flag = true;
            while (i >= 0 && j < n) {
                cn += (s[i][j] == '#');

                if (flag)
                    i--;
                else
                    j++;

                flag = !flag;
            }

            if (cn == cnt) {
                std::cout << "YES\n";
                continue;
            }
        }

        {
            int i = x1, j = y1, cn = 0;

            bool flag = false;
            while (i >= 0 && j < n) {
                cn += (s[i][j] == '#');

                if (flag)
                    i--;
                else
                    j++;

                flag = !flag;
            }

            if (cn == cnt) {
                std::cout << "YES\n";
                continue;
            }
        }

        int dx[]{1, -1, 0, 0};
        int dy[]{0, 0, 1, -1};

        int cn = 0;
        std::queue<std::pair<int, int>> q;

        q.emplace(x, y);
        s[x][y] = '.';
        cn++;
        while (q.size()) {
            auto [i, j] = q.front();

            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];

                if (x >= 0 && x < n && y >= 0 && y < n && s[x][y] == '#')
                    q.emplace(x, y), s[x][y] = '.', cn++;
            }
        }

        if (cn == cnt)
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}
