/**
 *    author:  feev1x
 *    created: 09.08.2025 17:12:48
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

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int64_t t, n, a, b, k; std::cin >> t >> n >> a >> b >> k;

    if (n < k) {
        std::cout << "0\n";
        exit(0);
    }

    if (n == 1) {
        std::cout << a << '\n';
        exit(0);
    }

    int64_t cb, ca, res;

    if (a > b) {
        std::swap(a, b);

        ca = n / 2;
        cb = (n + 1) / 2;
    } else {
        ca = (n + 1) / 2;
        cb = n / 2;
    }

    if (cb >= k)
        res = (cb * b + ca * a) / k;
    else {
        int64_t l = 0, r = b, ans = -1, x = k - cb;
        while (l <= r) {
            int64_t m = l + r >> 1;

            if (a - (x * m + ca - 1) / ca >= b - m)
                r = m - 1, ans = (a - (x * m + ca - 1) / ca == b - m ? m : -1);
            else
                l = m + 1;
        }

        if (ans == -1) {
            res = ca * a / x;
        } else if (ans < b) {
            int64_t ost = (x * ans % ca + (x * ans % ca == 0 ? ca : x)) - ca;
            res = ans + ((ca + cb) * (b - ans) - ost) / k + (ost > 0);
        } else {
            res = ans;
        }
    }

    std::cout << std::min(res, t) << '\n';
    return 0;
}
