/**
 *    author:  feev1x
 *    created: 11.02.2025 21:01:23
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        std::string s; std::cin >> s;

        int64_t n = 0;
        for (int i = 0; i < s.size(); ++i) {
            n *= 10;
            n += s[i] - '0';
        }

        std::reverse(s.begin(), s.end());

        s += "0000";

        int res = 11;
        std::vector<int> d(11);
        for (int i = 0; i < s.size(); ++i) {
            int dig = s[i] - '0';

            std::vector<int> nw;

            for (int j = 0; j < res; ++j) {
                if (dig == 7) {
                    res = std::min(res, j);
                    break;
                }

                nw.emplace_back((dig + 9 + d[j]) / 10);
                dig = (dig + 9 + d[j]) % 10;
            }

            d = nw;
        }

        int64_t ten = 10;
        for (int i = 1; i < s.size(); ++i) {
            int64_t dv = ten - 1;
            
            int dig = s[i] - '0';
            for (int j = 0; j < res; ++j) {
                if (dig == 7) {
                    res = std::min(res, j);
                    break;
                }

                int add = (dv * (j + 1) + n % ten) / ten;

                dig = (s[i] - '0' + add) % 10;
            }

            ten *= 10;
        }

        std::cout << res << '\n';
    }
    return 0;
}
