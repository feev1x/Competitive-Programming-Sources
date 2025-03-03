/**
 *    author:  feev1x
 *    created: 04.01.2025 19:20:42
**/
#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string s; std::cin >> s;

    if (s.size() <= 5) {
        int n = 0;

        for (int i = 0; i < s.size(); ++i) {
            n = n * 10 + s[i] - '0';
        }

        for (int a = n; a < 2 * n; ++a) {
            std::string t = std::to_string(a);

            int sum = 0;
            for (int i = 0; i < t.size(); ++i) {
                sum += t[i] - '0';
            }

            if (a % sum == 0) {
                t = std::to_string(a + 1);

                sum = 0;
                for (int i = 0; i < t.size(); ++i) {
                    sum += t[i] - '0';
                }

                if ((a + 1) % sum == 0) {
                    std::cout << a << '\n';

                    exit(0);
                }
            }
        }

        std::cout << "-1\n";

        exit(0);
    }

    std::string t(s.size(), '0');
    t[0] = '1';

    if (t == s) {
        t[1] = '1';

        std::cout << t << '\n';
    } else if (s[0] == '1') {
        t[0] = '2';

        std::cout << t << '\n';
    } else if (s[0] < '8') {
        t[0] = s[0] + 1;

        t[1] = 8 - (t[0] - '0') + '0';

        std::cout << t << '\n';
    } else {
        t = '1' + t;

        std::cout << t << '\n';
    }
    return 0;
}
