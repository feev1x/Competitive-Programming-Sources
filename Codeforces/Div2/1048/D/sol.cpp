/**
 *    author:  feev1x
 *    created: 08.09.2025 21:30:14
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
                sp[i][j] = std::min(sp[i - 1][j], sp[i - 1][j + (1 << i - 1)]);
    }
 
    inline int get(int l, int r) {
        int i = lg[r - l + 1];
 
        return std::min(sp[i][l], sp[i][r - (1 << i) + 1]);
    }
};

struct Bit {
    std::vector<int> p;
    int n;

    Bit(int _n) : n(_n) {
        p.assign(n + 1, n + 1);
    }

    inline void update(int r, int x) {
        for (; r <= n; r += r & -r)
            p[r] = std::min(p[r], x);
    }

    inline int get(int r) {
        int res = n + 1;

        for (; r >= 1; r -= r & -r)
            res = std::min(res, p[r]);

        return res;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n, q; std::cin >> n >> q;

        std::vector<int> a(n + 1), next(n + 1), nx(n + 1);
        for (int i = 1; i <= n; ++i)
            std::cin >> a[i];

        std::stack<int> stk;
        for (int i = n; i >= 1; --i) {
            while (stk.size() && a[stk.top()] > a[i])
                stk.pop();

            if (stk.size())
                next[i] = stk.top();
            else
                next[i] = n + 1;

            stk.emplace(i);
        }


        Bit bit(n);
        for (int i = n; i >= 1; --i) {
            nx[i] = bit.get(a[i]);

            bit.update(a[i], next[i]);
        }

        SpTable sp(nx);
        while (q--) {
            int l, r; std::cin >> l >> r;

            std::cout << (sp.get(l, r) > r ? "YES\n" : "NO\n");
        }
    }
    return 0;
}
