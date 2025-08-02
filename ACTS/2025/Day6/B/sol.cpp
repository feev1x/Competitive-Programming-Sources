/**
 *    author:  feev1x
 *    created: 26.07.2025 15:52:30
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
    
    int n, k; std::cin >> n >> k;

//    std::map<int, std::pair<int, int>> mp;
    int N = n;

    auto Hsh = [&](int x, int y) {
        return x * (N + 1) + y;
    };

    std::vector<int> ps(k), p3(n + 1, 1), pos(n + 1);

    int idx = 0;
    for (auto &u: ps)
        std::cin >> u, pos[u] = ++idx;

    for (int i = 1; i <= n; ++i) 
        p3[i] = p3[i - 1] * 3;

    std::unordered_map<int, int, custom_hash> dp;
    std::queue<std::pair<int, int>> q;
    std::unordered_map<int, bool, custom_hash> inq;

    q.emplace(0, 0);
    dp[Hsh(0, 0)] = 1;
    inq[Hsh(0, 0)] = true; 

    int64_t res = 0;
    while (q.size()) {
        auto [mask, ls] = q.front();


        q.pop();

        if (dp[Hsh(mask, ls)] == 0)
            continue;

        assert(dp[Hsh(mask, ls)] != 0);

        std::vector<int> d;

        int cnt = 1, fr = -1, las = -1, c2 = 0, cntls = 0;
        for (int i = 0; i < n; ++i)
            if (mask / p3[i] % 3 == 2)
                d.emplace_back(i + 1), cnt++, fr = (fr == -1 ? i : fr), c2++;
            else if (mask / p3[i] % 3)
                cnt++, fr = (fr == -1 ? i : fr);
            else
                las = i, cntls += (i + 1 > ls);


        if (cnt == N + 1) {
            res += dp[Hsh(mask, ls)];

            continue;
        }

        if (c2 == k && d.back() < las + 1)
            continue;

        int idx = std::lower_bound(ps.begin(), ps.end(), cnt) - ps.begin(), sz = ps.size() - idx;

        if (cntls < sz)
            continue;

        int st = 0;
        if (cntls == sz)
            if (pos[cnt] == 0)
                n = ls;

        if (pos[cnt] == 1)
            n = (fr == -1 ? n : fr);

        if (pos[cnt] == k)
            st = las, n = st + 1;

        if (pos[cnt] == 0 && ls == 0)
            st = 1;

        int nw = 0;

        while (nw < d.size() && d[nw] - 1 < st)
            nw++;

        for (int i = st; nw + 1 <= k && i <= std::min(n - 1, las); ++i) {
            if (mask / p3[i] % 3 == 2) {
                nw++;
                continue;
            }

            if (mask / p3[i] % 3)
                continue;

            if (nw + 1 == k && las != i)
                i = las;

            int n_mask = mask + p3[i] * 2;

            if (nw < d.size())
                n_mask -= p3[d[nw] - 1];

            if (pos[cnt]) {
                if (i + 1 > ls && pos[cnt] == nw + 1) {
                    dp[Hsh(n_mask, i + 1)] += dp[Hsh(mask, ls)];

                    if (!inq[Hsh(n_mask, i + 1)]) {
                        inq[Hsh(n_mask, i + 1)] = true;

                        q.emplace(n_mask, i + 1);
                    }
                }
            } else {
                dp[Hsh(n_mask, ls)] += dp[Hsh(mask, ls)];

                if (!inq[Hsh(n_mask, ls)]) {
                    inq[Hsh(n_mask, ls)] = true;

                    q.emplace(n_mask, ls);
                }
            }
        }

        n = N;
    }

    std::cout << res << '\n';
    return 0;
}
