#include <bits/stdc++.h>

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

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

    int n; std::cin >> n;

    std::string s; std::cin >> s;

    int cnt = 0, sum = std::count(s.begin(), s.end(), 'R');
    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    inv[n] = binpow(fac[n], MOD - 2);

    for (int i = n - 1; i > 1; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }

    auto C = [&](int n, int k) {
        return mul(fac[n], mul(inv[k], inv[n - k]));
    };

    std::vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'B') {
            a.emplace_back(cnt);
            cnt = 0;
        } else {
            cnt++;
        }
    }

    int on = n + 4;
    n = a.size();

    if (n == 1) {
        std::cout << "1\n";
        return 0;
    }

//    if (n == 2) {
//        std::cout << a[0] + 1 << '\n';
//        return 0;
//    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(on));
    dp[0][a[0]] = 1;

    int res = 0;
    for (int j = a.back(); j <= sum; ++j) {
        add_self(res, C(n - 2 + sum - j, n - 2));
    }
    
    std::cout << res << '\n';
    return 0;
}
