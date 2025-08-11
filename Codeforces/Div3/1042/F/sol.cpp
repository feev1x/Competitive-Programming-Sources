/**
 *    author:  feev1x
 *    created: 10.08.2025 21:29:12
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
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::string a, b; std::cin >> a >> b;

        a = ' ' + a;
        b = ' ' + b;

        std::vector<int64_t> p0(n + 1), p1(n + 1), pf0(n + 1), pf1(n + 1);

        std::vector<int64_t> idx(n + 1);
        for (int i = 1; i <= n; ++i) {
            idx[i] = i;
            p1[i] = p1[i - 1] + (b[i] == '1');
            p0[i] = p0[i - 1] + (b[i] == '0');
        }

        std::sort(idx.begin() + 1, idx.end(), [&](int i, int j) {
            return p1[i] - p0[i] < p1[j] - p0[j];
        });

        for (int i = 1; i <= n; ++i) {
            int j = idx[i];

            pf1[i] = pf1[i - 1] + p0[j];
            pf0[i] = pf0[i - 1] + p1[j];
        }

        int64_t cnt0 = 0, cnt1 = 0;

        int64_t res = 0;
        for (int i = 1; i <= n; ++i) {
            if (a[i] == '1')
                cnt1++;
            else
                cnt0++;

            int64_t l = 1, r = n, ans = -1, x = -(cnt1 - cnt0);
            while (l <= r) {
                int m = l + r >> 1;

                if (p1[idx[m]] - p0[idx[m]] >= x)
                    r = m - 1, ans = m;
                else
                    l = m + 1;
            }

            if (ans == -1)
                res += pf0[n] + cnt1 * n;
            else
                res += pf1[n] - pf1[ans - 1] + cnt0 * (n - ans + 1) + pf0[ans - 1] + cnt1 * (ans - 1);
        }

        std::cout << res << '\n';
    }
    return 0;
}
