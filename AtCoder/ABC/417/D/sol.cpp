/**
 *    author:  feev1x
 *    created: 02.08.2025 18:30:57
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
    
    int n; std::cin >> n;

    std::vector<int> p(n), b(n), a(n), pref(n + 1);
    for (int i = 0; i < n; ++i) {
        std::cin >> p[i] >> a[i] >> b[i];

        pref[i + 1] = pref[i] + b[i];
    }

    std::vector<std::array<int, 501>> res(n + 1);
    for (int j = 0; j <= 500; ++j)
        res[n][j] = j;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= 500; ++j) {
            if (p[i] >= j) {
                int x = j + a[i];

                int l = i, r = n - 1, ans = n;
                while (l <= r) {
                    int m = l + r >> 1;

                    int y = x - (pref[m + 1] - pref[i + 1]);

                    if (y > 500)
                        l = m + 1;
                    else
                        r = m - 1, ans = m;
                }

                if (ans == n || ans == n - 1)
                    res[i][j] = x - (pref[n] - pref[i + 1]);
                else
                    res[i][j] = res[ans + 1][x - (pref[ans + 1] - pref[i + 1])];
            } else {
                res[i][j] = res[i + 1][std::max(0, j - b[i])];
            }
        }
    }

    int q; std::cin >> q;
    while (q--) {
        int x; std::cin >> x;

        int l = -1, r = n - 1, ans = n;
        while (l <= r) {
            int m = l + r >> 1;

            int y = x - (pref[m + 1]);

            if (y > 500)
                l = m + 1;
            else
                r = m - 1, ans = m;
        }

        if (ans == n || ans == n - 1)
            std::cout << x - pref[n] << '\n';
        else
            std::cout << res[ans + 1][x - pref[ans + 1]] << '\n';
    }
    return 0;
}
