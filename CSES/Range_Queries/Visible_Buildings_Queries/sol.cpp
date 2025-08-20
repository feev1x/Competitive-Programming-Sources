/**
 *    author:  feev1x
 *    created: 19.08.2025 17:27:55
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

    std::stack<int> stk;
    std::vector<int> a(n + 1);
    std::vector<std::array<int, 20>> anc(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];

        for (int j = 0; j < 20; ++j)
            anc[i][j] = n + 1;
    }

    for (int i = n; i >= 1; --i) {
        while (stk.size() && a[stk.top()] <= a[i])
            stk.pop();

        if (stk.size()) {
            anc[i][0] = stk.top();

            for (int j = 1; anc[i][j - 1] <= n && j < 20; ++j)
                anc[i][j] = anc[anc[i][j - 1]][j - 1];
        }

        stk.emplace(i);
    }

    while (q--) {
        int l, r; std::cin >> l >> r;

        int u = l, res = 1;
        for (int i = 19; i >= 0; --i)
            if (anc[u][i] <= r)
                u = anc[u][i], res += 1 << i;

        std::cout << res << '\n';
    }

    return 0;
}
