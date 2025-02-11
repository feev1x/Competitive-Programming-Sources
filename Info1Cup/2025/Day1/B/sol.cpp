/**
 *    author:  feev1x
 *    created: 08.02.2025 17:56:38
**/
#include <bits/stdc++.h>
#include "cards.h"

//using ll = long long;

//static constexpr int MAX_N = 2e5;
//static constexpr int MOD = 1e9 + 7;
//int product(int a, int b) {
//
//    if(a > b) return 0;
//    if(a < 1) return 0;
//    if(b > MAX_N) return 0;
//
//    static int factorial[MAX_N + 5], inv_factorial[MAX_N + 5];
//    static bool calculated = false;
//
//    if (!calculated) {
//        factorial[0] = 1;
//        for (int i = 1; i <= MAX_N; i++)
//            factorial[i] = (ll) factorial[i - 1] * i % MOD;
//
//        inv_factorial[MAX_N] = 750007460;
//
//        for (int i = MAX_N - 1; i >= 0; i--)
//            inv_factorial[i] = (ll) inv_factorial[i + 1] * (i + 1) % MOD;
//
//        calculated = true;
//    }
//
//    return (ll) factorial[b] * inv_factorial[a - 1] % MOD;
//}

constexpr int MOD = 1e9 + 7;

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

inline int fac(int n) {
    return product(1, n);
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

inline int C(int n, int k) {
    return divide(fac(n), mul(fac(n - k), fac(k)));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    std::vector<int> a(n);
    for (auto &u: a) {
        std::cin >> u;
    }

    std::vector<std::tuple<int, int, int>> qs;
    std::vector<int> ans(q), ans2(q);

    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r; l--, r--;

        qs.emplace_back(l, r, i);
    }

    std::sort(qs.begin(), qs.end());

    int l = 0, r = 0;
    std::multiset<int> st;
    for (auto [L, R, i]: qs) {
        while (R >= r) {
            st.emplace(a[r++]);
        }

        while (L < l) {
            st.emplace(a[--l]);
        }

        while (R + 1 < r) {
            st.erase(st.find(a[--r]));
        }

        while (l < L) {
            st.erase(st.find(a[l++]));
        }

        int64_t sum = *st.rbegin();
        int sz = 1, nw = sum, res = 1;

        while (true) {
            auto it = st.upper_bound(nw / 2);

            if (it == st.begin()) {
                break;
            }

            --it;

            nw = *it;

            sz++;
            sum += nw;
        }

        ans[i] = sum;
    }

    for (int i = 0; i < q; ++i) {
        std::cout << ans[i] << ' ' << ans2[i] << "\n";
    }
    return 0;
}
