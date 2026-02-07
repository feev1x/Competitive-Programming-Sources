/**
 *    author:  feev1x
 *    created: 24.11.2025 16:24:08
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, m; std::cin >> n >> m;

        std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
        std::vector<int> x(n + 1), y(m + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> x[i];

        for (int j = 1; j <= m; ++j)
            std::cin >> y[j];

        std::vector<bool> used(n * m + 1);

        bool flag = true;
        for (int i = 1; i <= n; ++i) {
            if (used[x[i]])
                continue;

            int pos = -1;

            for (int j = 1; j <= m; ++j) {
                if (a[i][j] || y[j] < x[i])
                    continue;
                
                if (pos == -1 || y[pos] > y[j])
                    pos = j;
            }

            if (pos == -1) {
                flag = false;
                break;
            }

            a[i][pos] = x[i];
            used[x[i]] = true;
        }
        
        if (!flag) {
            std::cout << "No\n";
            continue;
        }

        for (int j = 1; j <= m; ++j) {
            if (used[y[j]])
                continue;

            int pos = -1;

            for (int i = 1; i <= n; ++i) {
                if (a[i][j] || y[j] > x[i])
                    continue;
                
                if (pos == -1 || x[pos] > x[i])
                    pos = i;
            }

            if (pos == -1) {
                flag = false;
                break;
            }

            a[pos][j] = y[j];
            used[y[j]] = true;
        }

        if (!flag) {
            std::cout << "No\n";
            continue;
        }

        std::vector<std::array<int, 3>> ps;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (!a[i][j])
                    ps.push_back({std::min(x[i], y[j]), i, j});

        std::sort(ps.begin(), ps.end(), std::greater<>());
        for (int val = 1; val <= n * m; ++val) {
            if (used[val])
                continue;

            if (val > ps.back()[0])
                flag = false, ps.pop_back();
            else
                a[ps.back()[1]][ps.back()[2]] = val, ps.pop_back();
        }

        for (int i = 1; i <= n; ++i) {
            int mx = 0;

            for (int j = 1; j <= m; ++j) {
                if (!a[i][j])
                    flag = false;

                mx = std::max(mx, a[i][j]);
            }

            if (mx != x[i])
                flag = false;
        }

        for (int j = 1; j <= m; ++j) {
            int mx = 0;

            for (int i = 1; i <= n; ++i) {
                if (!a[i][j])
                    flag = false;

                mx = std::max(mx, a[i][j]);
            }

            if (mx != y[j])
                flag = false;
        }


        if (!flag) {
            std::cout << "No\n";
            continue;
        }

        std::cout << "Yes\n";
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                std::cout << a[i][j] << " \n"[j == m];
    }
    return 0;
}
