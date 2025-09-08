/**   I FORGOT LONG LONG FUUUUUDGE
 *    author:  feev1x
 *    created: 07.09.2025 21:23:16
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

struct SpTable {
    std::vector<std::vector<int>> sp;
    std::vector<int> lg;
    int n;

    SpTable(std::vector<int> a) : n(a.size() - 1) {
        lg.resize(n + 1);

        for (int i = 2; i <= n; ++i)
            lg[i] = lg[i / 2] + 1;

        sp.resize(lg[n] + 1, std::vector<int>(n + 1));

        sp[0] = a;

        for (int i = 1; i <= lg[n]; ++i) 
            for (int j = 1; j + (1 << i) - 1 <= n; ++j)
                sp[i][j] = std::max(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
    }

    inline int get(int l, int r) {
        int i = lg[r - l + 1];

        return std::max(sp[i][l], sp[i][r - (1 << i) + 1]);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        for (int i = 1; i <= n; ++i)
            std::cin >> b[i];

        int64_t res = 0;

        SpTable sp(a);
        for (int64_t i = 1; i <= n; ++i) {
            if (a[i] == b[i]) {
                res += i * (n - i + 1);
                continue;
            }

            int64_t pos = -1;
            {
                int l = 1, r = i - 1, ans = -1;
                while (l <= r) {
                    int m = l + r >> 1;

                    if (sp.get(m, i - 1) >= std::max(a[i], b[i]))
                        l = m + 1, ans = m;
                    else
                        r = m - 1;
                }

                pos = ans;
            }

            if (pos == -1)
                continue;

            res += pos * (n - i + 1);
        }

        std::cout << res << '\n';
    }

    return 0;
}
