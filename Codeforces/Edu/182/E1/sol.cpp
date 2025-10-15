/**
 *    author:  feev1x
 *    created: 15.09.2025 21:56:00
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

constexpr int MOD = 998244353;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (res & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }
    
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int tt; std::cin >> tt;
    while (tt--) {
        int n; std::cin >> n;

        std::vector<int> a(n), next(n, -1), prev(n, -1);
        for (auto &u: a)
            std::cin >> u;

        {
            std::stack<int> stk;

            for (int i = 0; i < n; ++i) {
                while (stk.size() && a[stk.top()] <= a[i])
                    stk.pop();

                if (stk.size())
                    prev[i] = stk.top();

                stk.emplace(i);
            }
        }

        {
            std::stack<int> stk;

            for (int i = n - 1; i >= 0; --i) {
                while (stk.size() && a[stk.top()] <= a[i])
                    stk.pop();

                if (stk.size())
                    next[i] = stk.top();

                stk.emplace(i);
            }
        }

        std::vector<int> left, right;
        for (int i = 0; i != -1; i = next[i])
            left.emplace_back(a[i]);

        for (int i = n - 1; i != -1; i = prev[i])
            right.emplace_back(a[i]);

        std::vector<std::vector<std::array<int, 2>>> dpl(n, std::vector<std::array<int, 2>>(left.size(), {0, 0})),
            dpr(n, std::vector<std::array<int, 2>>(right.size(), {0, 0}));

        for (int i = 0; i < n; ++i)
            if (a[i] == left.front())
                dpl[i][0][1] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < left.size(); ++j) {
                add_self(dpl[i][j][0], dpl[i - 1][j][0]);
                add_self(dpl[i][j][0], dpl[i - 1][j][1]);

                if (left[j] >= a[i]) {
                    add_self(dpl[i][j][1], dpl[i - 1][j][0]);
                    add_self(dpl[i][j][1], dpl[i - 1][j][1]);
                }
            }

            for (int j = 0; j + 1 < left.size(); ++j)
                if (left[j + 1] == a[i]) {
                    add_self(dpl[i][j + 1][1], dpl[i - 1][j][0]);
                    add_self(dpl[i][j + 1][1], dpl[i - 1][j][1]);
                }
        }

        for (int i = 0; i < n; ++i)
            if (a[i] == right.front())
                dpr[i][0][1] = 1;

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < right.size(); ++j) {
                add_self(dpr[i][j][0], dpr[i + 1][j][0]);
                add_self(dpr[i][j][0], dpr[i + 1][j][1]);

                if (right[j] >= a[i]) {
                    add_self(dpr[i][j][1], dpr[i + 1][j][0]);
                    add_self(dpr[i][j][1], dpr[i + 1][j][1]);
                }
            }

            for (int j = 0; j + 1 < right.size(); ++j)
                if (right[j + 1] == a[i]) {
                    add_self(dpr[i][j + 1][1], dpr[i + 1][j][0]);
                    add_self(dpr[i][j + 1][1], dpr[i + 1][j][1]);
                }
        }

        int res = 0, sz = left.size();

        assert(left.back() == right.back());
        for (int i = 0; i < n; ++i)
            if (a[i] == left.back()) {
                add_self(res, mul(!i ? dpl[i].back()[1] : (left.size() == 1 ? 1 : (dpl[i - 1][sz - 2][0] + dpl[i - 1][sz - 2][1])) % MOD, dpr[i].back()[1]));

//                std::cout << (!i ? dpl[i].back()[1] : (dpl[i - 1][sz - 2][0] + dpl[i - 1][sz - 2][1]) % MOD) << ' ' 
//                    << dpr[i].back()[1] << '\n';
            }

        std::cout << res << '\n';
    }
    return 0;
}
