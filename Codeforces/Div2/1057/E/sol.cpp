/**
 *    author:  feev1x
 *    created: 10.10.2025 22:03:24
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

constexpr int N = 1e7 + 5;
constexpr int64_t INF = 1e18;

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res *= a;

        if (a > N || res > N)
            return N;

        a *= a;
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int q; std::cin >> q;

    std::vector<int> ans(q);
    std::vector<std::array<int, 3>> qq;
    std::vector<std::vector<int>> pr(N);
    std::vector<bool> prime(N, true);

    prime[1] = false;
    for (int i = 2; i < N; ++i)
        if (prime[i])
            for (int j = i; j < N; j += i)
                pr[j].emplace_back(i), prime[j] = true;

    for (int i = 0; i < q; ++i) {
        int n, m; std::cin >> n >> m;

        if (n <= 3) {
            std::cout << 0 << '\n';
            continue;
        }

        int u = n - 1;
        while (!prime[u])
            --u;

        int64_t res = 0;
        while (n > u) {
            std::vector<int> p;

            for (int i = u + 1; i <= n; ++i)
                for (auto pri: pr[i])
                    p.emplace_back(pri);

            std::sort(p.begin(), p.end());
            p.erase(unique(p.begin(), p.end()), p.end());

            int64_t ans = INF, v = -1;
            for (auto val: p) {
                int64_t fs = (u + val) / val * val, ls = ((n + val) / val - 1) * val;

                assert(fs <= n);

                int64_t cntl = (fs - 1) / val, cntr = ls / val;
                int64_t vl = val;
                while (vl <= ls)
                    cntl += (fs - 1) / vl, cntr += ls / vl, vl *= val;

                if (binpow(val, cntl + 1) <= m) {
                    if (ans > 0) {
                        ans = 0, v = fs;
                    } else if (ans == 0 && v < fs)
                        v = fs;
                } else if (binpow(val, cntr - cntl) <= m) {
                    for (int e = cntr - cntl; binpow(val, e) <= m; ++e) {
                        if (cntl / e != cntr / e) {
                            if (ans > cntl / e) {
                                ans = cntl / e, v = fs;
                            } else if (ans == cntl / e && v < fs)
                                v = fs;
                        }
                    }
                } else {
                    int e;

                    for (e = 0; binpow(val, e) <= m; ++e);

                    e--;

                    if (ans > cntl / e) {
                        ans = cntl / e, v = fs;
                    } else if (ans == cntl / e && v < fs)
                        v = fs;
                }
            }

            assert(v != -1);
            res += ans * (v - u);
        }
    }

    return 0;
}
