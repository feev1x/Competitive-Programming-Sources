/**
 *    author:  feev1x
 *    created: 24.11.2025 17:16:39
**/
#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
    
    if (a < 0)
        a += MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s; std::cin >> s;

    int n = s.size();

    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i)
        fac[i] = mul(fac[i - 1], i);

    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
        inv[i] = mul(inv[i + 1], i + 1);

    auto C = [&](int N, int K) {
        return mul(fac[N], mul(inv[K], inv[N - K]));
    };

    int res = 0;
    for (char dg = '0'; dg < '9'; ++dg) {
        int cntn = std::count(s.begin(), s.end(), dg + 1);

        int cntp = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == dg + 1)
                cntn--;

            if (s[i] == dg) {
                cntp++;

                if (cntn)
                    add_self(res, C(cntp + cntn - 1, cntn - 1)); }
        }
    }

    std::cout << res << '\n';
    return 0;
}
