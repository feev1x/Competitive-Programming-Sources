/**
 *    author:  feev1x
 *    created: 17.04.2025 08:55:06
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int cnt = 1, ml = 1, res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            ml = mul(ml, 2);
        }
    }

    res = ml;

    int sz = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] == '1') {
            ml = mul(ml, (MOD + 1) / 2);

            add_self(res, mul(cnt, ml));
        }

        sz++;
        cnt = mul(cnt, 3);
    }

    std::cout << res << '\n';
    return 0;
}
