/**
 *    author:  feev1x
 *    created: 11.09.2025 12:58:14
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

constexpr int N = 3e5 + 5;

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    int sq = std::sqrt(n);

    std::vector<int> a(n);
    std::vector<std::vector<std::array<int, 3>>> bl(sq + 1);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];

    std::vector<int64_t> ans(q);
    for (int i = 0; i < q; ++i) {
        int l, r; std::cin >> l >> r; l--, r--;

        bl[l / sq].push_back({r, l, i});
    }

    for (int j = 0; j <= sq; ++j) {
        std::sort(bl[j].begin(), bl[j].end());

        int L = -1, R = -1;

        std::unordered_map<int, int, custom_hash> mp;
        std::vector<int> cnt(N);
        for (auto [qr, ql, idx]: bl[j]) {
            if (L == -1)
                L = ql, R = ql - 1;

            int m;
            while (R < qr) {
                int val = a[R + 1];

                if (cnt[val]) {
                    mp[cnt[val]]--;
                    if (!mp[cnt[val]])
                        mp.erase(cnt[val]);
                }

                cnt[val]++;
                mp[cnt[val]]++;

                R++;
            }

            while (ql < L) {
                int val = a[L - 1];

                if (cnt[val]) {
                    mp[cnt[val]]--;
                    if (!mp[cnt[val]])
                        mp.erase(cnt[val]);
                }

                cnt[val]++;
                mp[cnt[val]]++;

                L--;
            }

            while (L < ql) {
                int val = a[L];

                if (cnt[val]) {
                    mp[cnt[val]]--;
                    if (!mp[cnt[val]])
                        mp.erase(cnt[val]);
                }

                cnt[val]--;
                if (cnt[val]) {
                    mp[cnt[val]]++;
                }

                L++;
            }

            int64_t l = 0, r = 0, an = 0;

            m = R - L + 1;

            std::vector<std::pair<int, int>> np;
            for (auto [key, val]: mp)
                np.emplace_back(key, val);

            std::sort(np.begin(), np.end());
            for (auto [key, val]: np) {
                an += ((int64_t)key * (m - key) + (int64_t)key * (key + 1) / 2) * val;

                an += (int64_t)l * (m - l - key) * (int64_t)((val + 1) / 2);

                int64_t y = (val + 1) / 2;
                an += (y * (y - 1) / 2) * (m - 2 * l) * key;

                y--;
                an -= (((y * (y + 1) * (2 * y + 1)) / 6) + (y * (y + 1) / 2)) * key * key;


                l += (int64_t)key * ((val + 1) / 2);

                std::swap(l, r);

                an += (int64_t)l * (m - l - key) * (int64_t)(val / 2);

                y = val / 2;
                an += (y * (y - 1) / 2) * (m - 2 * l) * key;

                y--;
                an -= (((y * (y + 1) * (2 * y + 1)) / 6) + (y * (y + 1) / 2)) * key * key;

                l += (int64_t)key * (val / 2);

                if (l > r)
                    std::swap(l, r);
            }

            ans[idx] = an;
        }
    }

    for (auto u: ans)
        std::cout << u << '\n';

    return 0;
}
