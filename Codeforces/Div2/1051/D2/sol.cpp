/**
 *    author:  feev1x
 *    created: 17.09.2025 21:07:40
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

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        n++;

        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        r++;

        for (; r <= n; r += r & -r)
            add_self(p[r], x);
    }

    inline int get(int r) {
        r++;

        int res = 0;

        for (; r >= 1; r -= r & -r)
            add_self(res, p[r]);

        return res;
    }

    inline int get(int l, int r) {
        return ((get(r) - get(l - 1)) % MOD + MOD) % MOD;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        std::vector jk(n + 1, Bit(n));
        std::vector kj(n + 1, Bit(n));

        jk[0].update(0, 1);
        kj[0].update(0, 1);
        for (int i = 1; i <= n; ++i) {
            std::vector<int> dpj(n + 1), dpk(n + 1);

            for (int j = a[i] + 1; j <= n; ++j)
                add_self(dpj[j], jk[j].get((j == 0 ? std::min(j, a[i]) : std::min(j - 1, a[i]))));

            for (int k = 0; k < a[i]; ++k)
                add_self(dpk[k], kj[k].get((k == 0 ? k : k + 1), a[i]));

            for (int j = 0; j <= n; ++j) {
                jk[j].update(a[i], dpj[j]);
                kj[a[i]].update(j, dpj[j]);
            }

            for (int k = 0; k <= n; ++k) {
                kj[k].update(a[i], dpk[k]);
                jk[a[i]].update(k, dpk[k]);
            }
        }

        int res = 0;
        for (int i = 0; i <= n; ++i)
            add_self(res, jk[i].get(n));

        std::cout << res << '\n';
    }
    return 0;
}
