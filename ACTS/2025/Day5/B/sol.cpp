/**
 *    author:  feev1x
 *    created: 08.09.2025 11:13:34
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

    inline void update(int r, int x) {
        r = n - r + 1;

        for (; r <= n; r += r & -r)
            p[r] = std::max(p[r], x);
    }

    inline int get(int r) {
        r = n - r + 1;

        int res = 0;
        for (; r >= 1; r -= r & -r)
            res = std::max(res, p[r]);

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<std::set<int>> st(n + 1);
    std::vector<int> p(n + 1), pos(n + 1), lis(n + 1), ans(n + 1, 1), d(n + 1);
    std::vector<std::array<int, 20>> anc(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> p[i], pos[p[i]] = i;

    Bit bit(n);

    ans[0] = 0;
    for (int i = n; i >= 1; --i) {
        lis[i] = bit.get(p[i]) + 1;

        bit.update(p[i], lis[i]);

        st[lis[i]].emplace(p[i]);

        if (st[lis[i] - 1].empty() || *st[lis[i] - 1].rbegin() < p[i])
            continue;

        if (st[lis[i] - 1].upper_bound(p[i]) == --st[lis[i] - 1].end()) {
            anc[i][0] = pos[*st[lis[i] - 1].rbegin()];

            for (int j = 1; j < 20; ++j)
                anc[i][j] = anc[anc[i][j - 1]][j - 1];

            d[i] = d[anc[i][0]] + 1;
        } else {
            int l = pos[*st[lis[i] - 1].upper_bound(p[i])], r = pos[*st[lis[i] - 1].rbegin()];

            if (d[l] > d[r])
                std::swap(l, r);

            int k = d[r] - d[l];
            for (int i = 0; i < 20; ++i)
                if (k >> i & 1)
                    r = anc[r][i];

            assert(l != r);

            for (int i = 19; i >= 0; --i)
                if (anc[l][i] != anc[r][i])
                    l = anc[l][i], r = anc[r][i];

            anc[i][0] = anc[l][0];
            for (int j = 1; j < 20; ++j)
                anc[i][j] = anc[anc[i][j - 1]][j - 1];

            d[i] = d[anc[i][0]] + 1;
        }

        ans[i] = ans[anc[i][0]] + 1;
    }

    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] - 1 << " \n"[i == n];
    return 0;
}
