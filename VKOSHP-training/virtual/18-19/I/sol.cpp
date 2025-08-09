/**
 *    author:  feev1x
 *    created: 09.08.2025 14:24:32
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

constexpr int64_t INF = std::numeric_limits<int64_t>::max();

inline int64_t mod(int64_t a, int64_t b) {
    return (a % b + b) % b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int64_t n, l, r, x, y, z, b1, b2; std::cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;

        std::vector<int64_t> a(n + 1);
        int64_t mn = 1e18, res = INF, pmo = 1ll << 32ll;
        for (int i = 1; i <= n; ++i) {
            int64_t ai, bi;

            if (i == 1)
                bi = b1;
            else if (i == 2)
                bi = b2;
            else {
                bi = mod(b1 * x + b2 * y + z, pmo);
                b1 = b2;
                b2 = bi;
            }

            ai = mod(bi, r - l + 1) + l;
            a[i] = ai;

            if (mn < ai)
                res = std::min(res, mn * ai);
            else
                mn = ai;
        }

        int64_t mx = -1e18;
        for (int i = n; i >= 1; --i) {
            if (a[i] < mx)
                res = std::min(res, a[i] * mx);
            else
                mx = a[i];
        }

        if (res == INF)
            std::cout << "IMPOSSIBLE\n";
        else
            std::cout << res << '\n';
    }
    return 0;
}
