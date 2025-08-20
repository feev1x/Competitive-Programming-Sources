/**
 *    author:  feev1x
 *    created: 19.08.2025 17:18:28
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

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r, int x) {
        for (; r <= n; r += r & -r)
            add_self(p[r], x);
    }

    inline int get(int r) {
        int res = 0;

        for (; r >= 1; r -= r & -r)
            add_self(res, p[r]);

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> a(n);
    for (auto &u: a)
        std::cin >> u;

    auto b = a;
    std::sort(b.begin(), b.end());

    for (auto &u: a)
        u = std::lower_bound(b.begin(), b.end(), u) - b.begin() + 1;
    
    Bit bit(n);
    for (int i = 0; i < n; ++i)
        bit.update(a[i], (bit.get(a[i] - 1) + 1) % MOD);

    std::cout << bit.get(n) << '\n';
    return 0;
}
