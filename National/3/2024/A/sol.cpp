/**
 *    author:  feev1x
 *    created: 10.03.2025 13:52:59
**/
#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k; std::cin >> n >> k;

    std::string s; std::cin >> s;

    auto Val = [&](char c) -> int {
        if ('0' <= c && c <= '9') {
            return c - '0';
        } else {
            return c - 'A' + 10;
        }
    };

    std::reverse(s.begin(), s.end());

    while (s.back() == '0') {
        s.pop_back();
    }

    int res = 0, ls = Val(s.back());
    for (int i = 0; i < n; ++i) {
        res += __builtin_popcount(Val(s[i]));
    }

    for (int i = 15; i >= 0; --i) {
        if (ls >> i & 1) {
            ls = i + 1;

            break;
        }
    }

    std::cout << res + (int)(s.size() - 1) * k + (ls - 1) << '\n';
    return 0;
}
