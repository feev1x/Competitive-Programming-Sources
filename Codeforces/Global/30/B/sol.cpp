/**
 *    author:  feev1x
 *    created: 25.11.2025 13:47:16
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);

        int eq = 0, val = 0;
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i], eq += (a[i] % 2 == 0), val = (a[i] % 2 == 0 ? a[i] : val);

        if (n <= 1000) {
            bool flag = false;
            for (int i = 1; !flag && i <= n; ++i)
                for (int j = i + 1; !flag && j <= n; ++j) {
                    if ((a[j] % a[i]) % 2 == 0) {
                        std::cout << a[i] << ' ' << a[j] << '\n';
                        flag = true;
                        break;
                    }
                }

            if (!flag)
                std::cout << "-1\n";

            continue;
        }

        if (eq > 1) {
            int cnt = 0;

            for (int i = 1; cnt < 2 && i <= n; ++i) {
                if (a[i] % 2 == 0)
                    std::cout << a[i] << " \n"[cnt++];
            }

            continue;
        }

        bool flag = false;
        for (int i = 2; i <= n; ++i) {
            if ((a[i] % a[i - 1]) % 2 == 0) {
                flag = true;
                std::cout << a[i - 1] << ' ' << a[i] << '\n';
                break;
            }

            if (val > a[i] && (val % a[i]) % 2 == 0) {
                flag = true;
                std::cout << a[i] << ' ' << val << '\n';
                break;
            }
        }

        if (!flag)
            std::cout << "-1\n";
    }
    return 0;
}
