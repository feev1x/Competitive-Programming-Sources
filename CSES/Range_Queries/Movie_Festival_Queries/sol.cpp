/**
 *    author:  feev1x
 *    created: 20.08.2025 11:41:50
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
    
    int n, q; std::cin >> n >> q;

    std::vector<int> mxl(n);
    std::vector<std::pair<int, int>> mov(n);
    for (auto &[l, r]: mov)
        std::cin >> l >> r;

    std::sort(mov.begin(), mov.end(), [&](std::pair<int, int> x, std::pair<int, int> y) {
        return x.second < y.second || x.second == y.second && x.first > y.first;
    });

    auto vom = mov;

    std::map<std::pair<int, int>, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[mov[i]] = i;

        if (i)
            mxl[i] = std::max(mxl[i - 1], mov[i].first);
        else
            mxl[i] = mov[i].first;
    }

    std::sort(vom.begin(), vom.end(), [&](std::pair<int, int> x, std::pair<int, int> y) {
        return x.first < y.first || x.first == y.first && x.second < y.second;
    });

    int idx = n;
    std::vector<std::array<int, 20>> anc(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 20; ++j)
            anc[i][j] = n;

    for (int i = n - 1, j = n - 1; i >= 0; --i) {
        while (j >= 0 && vom[j].first >= mov[i].second) {
            if (idx == n || vom[j].second < mov[idx].second)
                idx = mp[vom[j]];

            j--;
        }

        anc[i][0] = idx;
        for (int j = 1; anc[i][j - 1] < n && j < 20; ++j)
            anc[i][j] = anc[anc[i][j - 1]][j - 1];
    }

    while (q--) {
        int a, b; std::cin >> a >> b;

        int l = 0, r = n - 1, ans = -1;
        while (l <= r) {
            int m = l + r >> 1;

            if (mxl[m] >= a)
                r = m - 1, ans = m;
            else
                l = m + 1;
        }
        
        if (ans == -1 || mov[ans].second > b) {
            std::cout << "0\n";
            continue;
        }

        int u = ans, res = 1;
        for (int i = 19; i >= 0; --i)
            if (anc[u][i] < n && mov[anc[u][i]].second <= b)
                u = anc[u][i], res += 1 << i;

        std::cout << res << '\n';
    }

    return 0;
}
