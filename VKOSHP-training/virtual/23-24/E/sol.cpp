#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7;

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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n; std::cin >> n;

    std::array<int, 3> cnt{0, 0, 0};
    std::vector<int> fac(n + 1, 1), inv(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fac[i] = mul(fac[i - 1], i);
    }

    inv[n] = binpow(fac[n], MOD - 2);
    for (int i = n - 1; i > 1; --i) {
        inv[i] = mul(inv[i + 1], i + 1);
    }

    auto P = [&](int n, int k) {
        return mul(fac[n], inv[n - k]);
    };

    for (int i = 1; i <= n; ++i) {
        int u; std::cin >> u;

        cnt[u % 3]++;
    }

    if (std::abs(cnt[1] - cnt[2]) == 0 || std::abs(cnt[1] - cnt[2]) > 2) {
        std::cout << "0\n";
        exit(0);
    }

    if (cnt[1] > cnt[2]) {
        std::swap(cnt[1], cnt[2]);
    }

    std::cout << mul(mul(fac[cnt[1]], fac[cnt[2]]), P(n - 1, cnt[0])) << '\n';
    return 0;
}
