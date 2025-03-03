/**
 *    author:  feev1x
 *    created: 13.02.2025 14:57:39
**/
#include <bits/stdc++.h>

int main() {
    std::freopen("leftout.in", "r", stdin);
    std::freopen("leftout.out", "w", stdout);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::vector<bool>> a(n + 1, std::vector<bool>(n + 1));
    for (int i = 1; i <= n; ++i) {
        std::string s; std::cin >> s;

        for (int j = 1; j <= n; ++j) {
            a[i][j] = s[j - 1] == 'R';
        }
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = (a[i][j] ^ a[1][j]);
        }
    }


    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            a[i][j] = (a[i][j] ^ a[i][1]);
        }
    }

    for (int i = 1; i <= n; ++i) {
        a[i][1] = a[1][i] = 0;
    }

    int cnt = 0;
    bool flag = true;
    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (a[i][j] != 1) {
                flag = false;
            } else {
                cnt++;
            }
        }
    }

    if (flag) {
        std::cout << "1 1\n";

        exit(0);
    }

    if (!cnt) {
        std::cout << "-1\n";

        exit(0);
    }

    if (cnt == n - 1) {
        for (int i = 2; i <= n; ++i) {
            cnt = 0;
            
            for (int j = 2; j <= n; ++j) {
                cnt += a[i][j];
            }

            if (cnt == n - 1) {
                std::cout << i << " 1\n";
//                std::cout << "1 " << i << '\n';

                exit(0);
            }
        }


        for (int i = 2; i <= n; ++i) {
            cnt = 0;
            
            for (int j = 2; j <= n; ++j) {
                cnt += a[j][i];
            }

            if (cnt == n - 1) {
//                std::cout << i << " 1\n";
                std::cout << "1 " << i << '\n';

                exit(0);
            }
        }

        std::cout << "-1\n";

        exit(0);
    }

    if (cnt != 1) {
        std::cout << "-1\n";
        
        exit(0);
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= n; ++j) {
            if (a[i][j]) {
                std::cout << i << ' ' << j << '\n';

                exit(0);
            }
        }
    }

    std::cout << "-1\n";
    return 0;
}
