/**
 *    author:  feev1x
 *    created: 27.02.2025 20:41:43
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, x; int64_t k; std::cin >> n >> x >> k;

        std::string s; std::cin >> s;

        int sec = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                x--;
            } else {
                x++;
            }

            if (x == 0) {
                sec = i + 1;

                break;
            }
        }

        if (sec == -1) {
            std::cout << "0\n";

            continue;
        }

        int sec1 = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'L') {
                x--;
            } else {
                x++;
            }

            if (x == 0) {
                sec1 = i + 1;

                break;
            }
        }

        if (sec1 == -1) {
            std::cout << "1\n";

            continue;
        }

        k -= sec;

        std::cout << k / sec1 + 1 << '\n';
    }
    return 0;
}
