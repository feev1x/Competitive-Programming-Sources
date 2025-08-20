/**
 *    author:  feev1x
 *    created: 19.08.2025 17:41:02
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

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.resize(n + 1);
    }

    inline void update(int r) {
        for (; r <= n; r += r & -r)
            p[r]++;
    }

    inline int get(int r) {
        int res = 0;

        for (; r >= 1; r -= r & -r)
            res += p[r];

        return res;
    }

    inline int get(int l, int r) {
        return get(r) - get(l);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q; std::cin >> n >> q;

    int sq = std::sqrt(n);

    std::vector<int> a(n);
    for (auto &u: a) 
        std::cin >> u;

    auto b = a;
    b.emplace_back(0);

    std::sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 0; i < n; ++i)
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    std::vector<int> ans(q);

    std::vector<std::vector<std::tuple<int, int, int>>> lq(n), rq(n);
    for (int i = 0; i < q; ++i) {
        int l, r, x, y; std::cin >> l >> r >> x >> y; --l, --r;

        x = std::lower_bound(b.begin(), b.end(), x) - b.begin() - 1;
        y = std::upper_bound(b.begin(), b.end(), y) - b.begin() - 1;

        if (l)
            lq[l - 1].emplace_back(x, y, i);

        rq[r].emplace_back(x, y, i);
    }

    Bit bit(n);
    for (int i = 0; i < n; ++i) {
        bit.update(a[i]);

        for (auto [x, y, idx]: lq[i])
            ans[idx] -= bit.get(x, y);

        for (auto [x, y, idx]: rq[i])
            ans[idx] += bit.get(x, y);
    }

    for (int i = 0; i < q; ++i)
        std::cout << ans[i] << '\n';

    return 0;
}
