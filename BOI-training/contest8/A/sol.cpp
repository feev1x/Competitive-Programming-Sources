/**
 *    author:  feev1x
 *    created: 19.09.2025 11:26:25
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

constexpr int MOD = 1e9 + 7;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int mod(int a) {
    return (a % MOD + MOD) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::vector<int> h(n + 1), w(n + 1), prev(n + 1), next(n + 1, n + 1);
    std::vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> h[i];

    for (int i = 1; i <= n; ++i)
        std::cin >> w[i], p[i] = (p[i - 1] + w[i]) % MOD;

    {
        std::stack<int> stk;

        for (int i = 1; i <= n; ++i) {
            while (stk.size() && h[stk.top()] >= h[i])
                stk.pop();

            if (stk.size())
                prev[i] = stk.top();

            stk.emplace(i);
        }
    }

    {
        std::stack<int> stk;

        for (int i = n; i >= 1; --i) {
            while (stk.size() && h[stk.top()] > h[i])
                stk.pop();

            if (stk.size())
                next[i] = stk.top();

            stk.emplace(i);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int cnth = mul(mul(h[i], h[i] + 1), (MOD + 1) / 2);

        int l = mod(p[i - 1] - p[prev[i]]), r = mod(p[next[i] - 1] - p[i]);
        add_self(res, mul(mul(l, r), cnth));
        add_self(res, mul(mul(w[i], l), cnth));
        add_self(res, mul(mul(w[i], r), cnth));
        add_self(res, mul(mul(mul(w[i], w[i] + 1), (MOD + 1) / 2), cnth));
    }

    std::cout << res << '\n';
    return 0;
}
