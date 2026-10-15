#include <bits/stdc++.h>

#define int int64_t

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::map<int, int> mp, mp2;
    int64_t ml = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?') {
            ml *= (s[i] - '0');
        }
    }
    mp[ml] = 1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            std::map<int, int> new_mp;
            for (int d = 0; d <= 9; ++d) {
                for (auto [key, val]: mp) {
                    new_mp[key * d] += val;
                }
            }
            std::swap(new_mp, mp);
        }
    }

    ml = 1;
    for (int i = n; i < 2 * n; ++i) {
        if (s[i] != '?') {
            ml *= (s[i] - '0');
        }
    }
    mp2[ml] = 1;
    for (int i = n; i < 2 * n; ++i) {
        if (s[i] == '?') {
            std::map<int, int> new_mp;
            for (int d = 0; d <= 9; ++d) {
                for (auto [key, val]: mp2) {
                    new_mp[key * d] += val;
                }
            }
            std::swap(new_mp, mp2);
        }
    }

    int res = 0;
    for (auto [key, val]: mp) {
        res += val * mp2[key];
    }
    std::cout << res << '\n';
    return 0;
}
