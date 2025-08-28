/**
 *    author:  feev1x
 *    created: 21.08.2025 21:07:44
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

int MOD, P;
constexpr int N = 1e6 + 5;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

#define rnd(l, r) std::uniform_int_distribution<int64_t>(l, r)(rng)

inline bool prime(int n) {
    if (n == 1)
        return false;

    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;

    return true;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    MOD = 1e9 + 7;

    P = 31659349;

    std::vector<int> pow_p(N, 1);
    for (int i = 1; i < N; ++i)
        pow_p[i] = mul(pow_p[i - 1], P);

    int tt; std::cin >> tt;
    while (tt--) {
        auto Get = [&](std::vector<std::string> s) {
            int n = s.size(), m = s[0].size();

            std::vector hl(n + 1, std::vector<int>(m + 1));
            std::vector hlr(n + 1, std::vector<int>(m + 1));
            std::vector hu(n + 1, std::vector<int>(m + 1));
            std::vector hd(n + 2, std::vector<int>(m + 1));
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j) {
                    hl[i + 1][j + 1] = (hl[i + 1][j] + mul(pow_p[j + 1], s[i][j])) % MOD;
                    hlr[i + 1][j + 1] = (mul(hlr[i + 1][j], P) + mul(s[i][j], P)) % MOD;
                }

            for (int j = 1; j <= m; ++j)
                for (int i = 1; i <= n; ++i)
                    hu[i][j] = (hu[i - 1][j] + mul(pow_p[i], hl[i][j] % MOD)) % MOD;

            for (int j = 1; j <= m; ++j)
                for (int i = n; i >= 1; --i)
                    hd[i][j] = (hd[i + 1][j] + mul(pow_p[n - i + 1], hlr[i][j] % MOD)) % MOD;

            auto Hd = [&](int i, int l, int r) {
                int res = hd[l][i] - hd[r + 1][i];

                if (res < 0)
                    res += MOD;

                return mul(res, pow_p[N - n + r - 1]);
            };

            auto Hu = [&](int i, int l, int r) {
                int res = hu[r][i] - hu[l - 1][i];

                if (res < 0)
                    res += MOD;

                return mul(res, pow_p[N - l]);
            };

            int res = (n * 2 - 1) * (m * 2 - 1) - n * m;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j) {
                    int mid = n + i >> 1;

                    bool flag = false;
                    if ((n - i + 1) & 1)
                        flag = Hu(j, i, mid) == Hd(j, mid, n);
                    else
                        flag = Hu(j, i, mid) == Hd(j, mid + 1, n);

                    if (flag)
                        res = std::min(res, (n + i - 1) * (m * 2 - j) - n * m);

                    mid = i + 1 >> 1;

                    flag = false;
                    if (i & 1)
                        flag = Hu(j, 1, mid) == Hd(j, mid, i);
                    else
                        flag = Hu(j, 1, mid) == Hd(j, mid + 1, i);

                    if (flag)
                        res = std::min(res, (n * 2 - i) * (m * 2 - j) - n * m);
                }

            return res;
        };

        auto Gt = [&](std::vector<std::string> &s) {
            int n = s.size(), m = s[0].size();

            auto sr = s;
            for (auto &u: sr)
                std::reverse(u.begin(), u.end());

            return std::min(Get(s), Get(sr));
        };

        int n, m; std::cin >> n >> m;
        
        std::vector<std::string> s(n);
        for (auto &u: s)
            std::cin >> u;

//        std::vector<std::string> t(m);
//        for (int i = 0; i < m; ++i)
//            for (int j = 0; j < n; ++j)
//                t[i] += s[j][i];
//
        std::cout << Gt(s) << '\n';
    }

    return 0;
}

