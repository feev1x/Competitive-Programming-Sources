/**
 *    author:  feev1x
 *    created: 19.08.2025 16:03:48
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

struct Sptable {
    std::vector<std::vector<int>> sp;
    std::vector<int> lg;
    int n;

    Sptable(std::vector<int> a) : n(a.size() - 1) {
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
    
    int n; std::cin >> n;

    std::vector<int> a(n + 1), pv(n + 1);
    std::map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        pv[i] = mp[a[i]];
        mp[a[i]] = i;
    }

    Sptable sp(pv);

    int64_t res = 0;
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n, ans = i;

        while (l <= r) {
            int m = l + r >> 1;

            if (sp.get(i, m) >= i)
                r = m - 1;
            else
                l = m + 1, ans = m;
        }

        res += ans - i + 1;
    }

    std::cout << res << '\n';
    return 0;
}
