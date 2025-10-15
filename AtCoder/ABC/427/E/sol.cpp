/**
 *    author:  feev1x
 *    created: 11.10.2025 18:34:43
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

std::string S = "............";

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; std::cin >> n >> m;

    n += 24, m += 24;

    std::vector<std::string> s(n + 1);

    int x, y;

    std::vector<std::array<int, 4>> dirt;
    for (int i = 1; i <= 12; ++i)
        for (int j = 0; j <= m; ++j)
            s[i] += '.';

    for (int i = n - 11; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            s[i] += '.';

    for (int i = 13; i <= n - 12; ++i) {
        std::cin >> s[i];

        std::string ns = " " + S;

        ns += s[i];

        ns += S;

        s[i] = ns;

        for (int j = 1; j <= n; ++j) {
            if (s[i][j] == '#')
                dirt.push_back({n - j + 1, j, n - i + 1, i});
            else if (s[i][j] == 'T')
                x = i, y = j;
        }
    }

    auto Bfs = [](int X, int Y, std::vector<std::string> &s) {
        int n = s.size() - 1, m = s[1].size() - 1;

        std::vector dis(n + 1, std::vector<int>(m + 1, 1e9));
        std::queue<std::pair<int, int>> q;

        q.emplace(X, Y);
        dis[X][Y] = 0;

        int dx[]{1, -1, 0, 0};
        int dy[]{0, 0, 1, -1};
        while (q.size()) {
            auto [i, j] = q.front();

            q.pop();
            for (int k = 0; k < 4; ++k) {
                int x = dx[k] + i, y = dy[k] + j;

                if (x && y && x <= n && y <= n && dis[x][y] > dis[i][j] + 1) {
                    dis[x][y] = dis[i][j] + 1;
                    q.emplace(x, y);
                }
            }
        }

        return dis;
    };

    auto d1 = Bfs(x, y, s);

    int res = 1e9;
    for (int x1 = 1; x1 <= n; ++x1)
        for (int y1 = 1; y1 <= m; ++y1) {
            if (s[x1][y1] == '#')
                continue;

            int left = y - y1, right = y1 - y, up = x - x1, down = x1 - x;

            std::vector<std::pair<int, int>> bck;
            for (auto [lf, rg, u, dw]: dirt)
                if (left >= lf || right >= rg || up >= u || down >= dw)
                    s[dw][rg] = '.', bck.emplace_back(dw, rg);

            auto d2 = Bfs(x1, y1, s);
            for (int x2 = 1; x2 <= n; ++x2)
                for (int y2 = 1; y2 <= m; ++y2) {
                    if (s[x2][y2] == '#')
                        continue;

                    
                    int left = y - y2, right = y2 - y, up = x - x2, down = x2 - x;
                    std::vector<std::pair<int, int>> bck;
                    for (auto [lf, rg, u, dw]: dirt)
                        if ((left >= lf || right >= rg || up >= u || down >= dw) && s[dw][rg] == '#')
                            s[dw][rg] = '.', bck.emplace_back(dw, rg);

                    auto d3 = Bfs(x2, y2, s);
                    for (int x3 = 1; x3 <= n; ++x3)
                        for (int y3 = 1; y3 <= m; ++y3) {
                            if (s[x3][y3] == '#')
                                continue;

                            int left = y - y3, right = y3 - y, up = x - x3, down = x3 - x;
                            std::vector<std::pair<int, int>> bck;
                            for (auto [lf, rg, u, dw]: dirt)
                                if ((left >= lf || right >= rg || up >= u || down >= dw) && s[dw][rg] == '#')
                                    s[dw][rg] = '.', bck.emplace_back(dw, rg);

                            auto d4 = Bfs(x3, y3, s);
                            for (int x4 = 1; x4 <= n; ++x4)
                                for (int y4 = 1; y4 <= m; ++y4) {
                                    if (s[x4][y4] == '#')
                                        continue;

                                    int left = y - y4, right = y4 - y, up = x - x4, down = x4 - x;
                                    std::vector<std::pair<int, int>> bck;

                                    bool flag = true;
                                    for (auto [lf, rg, u, dw]: dirt)
                                        if ((left >= lf || right >= rg || up >= u || down >= dw) && s[dw][rg] == '#')
                                            s[dw][rg] = '.', bck.emplace_back(dw, rg);
                                        else if (s[dw][rg] == '#')
                                            flag = false;


                                    if (flag)
                                        res = std::min(res, d1[x1][y1] + d2[x2][y2] + d3[x3][y3] + d4[x4][y4]);

                                    for (auto [i, j]: bck)
                                        s[i][j] = '#';
                                }
                            for (auto [i, j]: bck)
                                s[i][j] = '#';
                        }

                    for (auto [i, j]: bck)
                        s[i][j] = '#';
                }

            for (auto [i, j]: bck)
                s[i][j] = '#';
        }

    return 0;
}
