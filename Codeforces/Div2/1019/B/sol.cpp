/**
 *    author:  feev1x
 *    created: 21.04.2025 20:38:33
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::string s; std::cin >> s;

        std::string ss;
        for (int i = 0; i < n; ++i) {
            if (ss.empty() || ss.back() != s[i]) {
                ss += s[i];
            }
        }

        int res = n + ss.size() - 1;

        if (ss.front() == '1') {
            res++;
        }

        if (ss.size() > 3) {
            res -= 2;
        } else if (ss.size() == 2) {
            if (ss.front() == '1') {
                res--;
            }
        } else if (ss.size() == 3) {
            if (ss.front() == '1') {
                res--;
            }

            res--;
        }

        std::cout << res << '\n';
    }
    return 0;
}
