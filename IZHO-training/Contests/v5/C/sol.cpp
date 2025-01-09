/**
 *    author:  feev1x
 *    created: 09.01.2025 12:34:28
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline void sub_self(int &a, int b) {
    a -= b;

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; int64_t A1, B1; std::cin >> n >> A1 >> B1;    

    std::string A = std::to_string(A1 - 1), B = std::to_string(B1);
    std::vector<int> a(n + 1), fac(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        fac[i] = mul(i, fac[i - 1]);
    }

    auto C = [&](int n, int k) {
        return divide(fac[n], mul(fac[n - k], fac[k]));
    };

    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;

        std::vector dp(B.size(), std::vector<std::array<int, 2>>(r + 1, {0, 0}));
        std::vector used(B.size(), std::vector<std::array<bool, 2>>(r + 1, {false, false}));
        std::string s = B;

        auto Dfs = [&](auto &&self, int len, int i, bool flag) {
            if (i == r + 1 || len == s.size()) {
                return int(len == s.size());
            }

            int res = 0;
            if (flag && a[i] == s[i - 1] - '0' || !flag) {
                add_self(res, self(self, len + 1, i + 1, flag));
            } else if (a[i] < s[i - 1] - '0') {
                add_self(res, self(self, len + 1, i + 1, false));
            }

            add_self(res, self(self, len, i + 1, flag));
            used[len][i][flag] = true;
            return dp[len][i][flag] = res;
        };

        int R = Dfs(Dfs, 0, l, true);
        for (int i = A.size(); i < B.size(); ++i) {
            add_self(R, mul(C(r - l + 1, i), 1 << i));
        }

        dp.assign(B.size(), std::vector<std::array<int, 2>>(r + 1, {0, 0}));
        used.assign(B.size(), std::vector<std::array<bool, 2>>(r + 1, {false, false}));

        s = A;
        sub_self(R, Dfs(Dfs, 0, l, true));

        std::cout << R << '\n';
    }
    return 0;
}
