/**
 *    author:  feev1x
 *    created: 29.01.2025 10:51:28
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e6 + 3;

int fact[MOD];

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
         a -= MOD;
    }
}

inline int mul(int64_t a, int64_t b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int64_t a, int64_t n) {
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

inline int fac(int64_t n) {
    if (n >= MOD) {
        return 0;
    }

    if (fact[n]) {
        return fact[n];
    }

    if (n == 0) {
        return 1;
    }

    return fact[n] = mul(n, fac(n - 1));
}

inline int divide(int64_t a, int64_t b) {
    return mul(a, binpow(b, MOD - 2));
}

inline int fac(int64_t l, int64_t r) {
    if (l > r) {
        return 1;
    }

    if (l == r) {
        return l % MOD;
    }

    if (r >= MOD && l <= MOD) {
        return 0;
    }

    if (r < MOD) {
        return divide(fac(r), fac(l));
    }

    if (r - l + 1 >= MOD || l % MOD >= r % MOD) {
        return 0;
    }

    return divide(fac(r % MOD), fac(l % MOD));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t n, Q; std::cin >> n >> Q;

    std::vector<int64_t> x(Q), y(Q);
    std::multiset<std::pair<int64_t, int64_t>> st; 
    std::multiset<int64_t> st1;
    for (int i = 0; i < Q; ++i) {
        std::cin >> x[i] >> y[i]; x[i]--, --y[i];

        st.emplace(x[i], -5);
        st.emplace(y[i], x[i]);
    }
    
    st.emplace(n, -5);
    st1.emplace(0);
    int64_t l = 0;

    int64_t res = 1;
    for (auto it = st.begin(); it != st.end(); ++it) {
        int64_t val = *--st1.end(), left = l - val, right = it->first - val + 1;

        if (it->second == -5 && it->first - 1 >= l) {
            res = mul(res, fac(left, right - 1));
            l = it->first;
        } else if (it->second != -5 && it->first >= l) {
            res = mul(res, fac(left, right));
            l = it->first + 1;
        }

        if (it->second == -5) {
            st1.emplace(it->first);
        } else {
            st1.erase(st1.find(it->second));
        }
    }


    std::cout << res << '\n';
    return 0;
}
