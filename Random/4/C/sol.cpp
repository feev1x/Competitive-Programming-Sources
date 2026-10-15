#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m; std::cin >> n >> m;

    std::vector<std::vector<int>> a(n, std::vector<int>(m));
    if (n % 4 == 0 || m % 4 == 0 || (n % 2 == 0 && m % 2 == 0)) {
        std::cout << "YES\n";

        if (n % 4 == 0) {
            int nw = 0;

            for (int j = 0; j < m; ++j) {
                for (int i = 0; i < n; ++i) {
                    nw += (i % 4 == 0);

                    a[i][j] = nw;
                }
            }
        } else if (m % 4 == 0) {
            int nw = 0;

            for (int j = 0; j < n; ++j) {
                for (int i = 0; i < m; ++i) {
                    nw += (i % 4 == 0);

                    a[j][i] = nw;
                }
            }
        } else {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    a[i][j] = (i / 2) * (n / 2) + j / 2 + 1;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                std::cout << a[i][j] << " \n"[j == m - 1];
            }
        }

        return 0;
    }

    std::cout << "NO\n";
    return 0;
}
