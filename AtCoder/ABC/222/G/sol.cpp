/**
 *    author:  feev1x
 *    created: 16.10.2025 16:13:57
**/
#include <bits/stdc++.h>

struct custom_hash {
   static uint64_t splitmix64(uint64_t x) {
       x += 0x9e3779b97f4a7c15;
       x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
       x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
       return x ^ (x >> 31);
   }

   size_t operator()(uint64_t x) const {
       static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
       return splitmix64(x + FIXED_RANDOM);
   }
};

constexpr int SQ = 1e4;

int MOD;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

using m22 = std::array<std::array<int, 2>, 2>;

inline m22 operator*(const m22 &a, const m22 &b) {
    m22 c{};

    c[0][0] = (1LL * a[0][0] * b[0][0] + 1LL * a[0][1] * b[1][0]) % MOD;
    c[0][1] = (1LL * a[0][0] * b[0][1] + 1LL * a[0][1] * b[1][1]) % MOD;
    c[1][0] = (1LL * a[1][0] * b[0][0] + 1LL * a[1][1] * b[1][0]) % MOD;
    c[1][1] = (1LL * a[1][0] * b[0][1] + 1LL * a[1][1] * b[1][1]) % MOD;

    return c;
}

inline m22 binpow(m22 a, int n) {
    m22 res{};

    res[0][0] = res[1][1] = 1;

    while (n) {
        if (n & 1)
            res = res * a;

        a = a * a;
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int tt; std::cin >> tt;
    while (tt--) {
        int k; std::cin >> k;

        MOD = k;
        int mod = 2 % k, ans = -1;

        std::map<int, int> mp;
        bool flag = false;
        int ls = std::min(SQ, k);

        mp[0] = 0;
        for (int sz = 1; sz <= std::min(SQ, k); ++sz) {
            if (mod == 0) {
                ans = sz;
                flag = true;
                break;
            }

            if (mp[mod]) {
                flag = true;
                break;
            }

            mp[mod] = sz;
            mod = (mod * 10 + 2) % k;

            ls--;
        }

        if (flag) {
            std::cout << ans << '\n';
            continue;
        }

        m22 a{};

        a[0][0] = 10, a[0][1] = 2;
        a[1][1] = 1;

        bool brek = false;
        for (int sz = SQ + 1; !brek; sz += SQ) {
            if (sz > k) {
                sz = k;
                brek = true;
            }

            m22 asz = binpow(a, sz);

            int val = asz[0][1];

            if (!val) {
                ans = sz;
                break;
            }

            if (mp.count(val)) {
                sz -= mp[val];

                asz = binpow(a, sz);

                val = asz[0][1];

                if (!val)
                    ans = sz;

                break;
            }
        }

        std::cout << ans << '\n';
    }

    return 0;
}
