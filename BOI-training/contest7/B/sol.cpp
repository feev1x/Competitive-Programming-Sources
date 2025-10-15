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

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int solve(int n, int m, std::vector<std::vector<int>>& splits) {
    std::vector<int> fac(n + 1, 1), inv(n + 1);

    for (int i = 1; i <= n; ++i)
        fac[i] = mul(fac[i - 1], i);

    inv[n] = divide(1, fac[n]);
    for (int i = n - 1; i >= 1; --i)
        inv[i] = mul(inv[i + 1], i + 1);

    auto C = [&](int N, int K) {
        return mul(fac[N], mul(inv[K], inv[N - K]));
    };

    std::set<std::vector<int>> st;
    bool flag = true;
    for (auto a: splits) {
        std::set<std::vector<int>> new_st;
        
        for (int mask = 0; mask < 1 << n; ++mask) {
            int i = 0, j = __builtin_popcount(mask);

            std::vector<int> v;
            for (int k = 0; k < n; ++k) {
                if (mask >> k & 1)
                    v.emplace_back(a[i++]);
                else
                    v.emplace_back(a[j++]);
            }

            if (st.find(v) != st.end() || flag)
                new_st.emplace(v);
        }

        flag = false;
        st = new_st;
    }

	return st.size();
}
