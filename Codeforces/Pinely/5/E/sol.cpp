/**
 *    author:  feev1x
 *    created: 31.10.2025 00:27:21
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

constexpr int MOD = 998244353, N = 1e5 + 5;

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD)
        a -= MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1)
            res = mul(res, a);

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::vector<int> fac(N, 1), inv(N, 1);
    for (int i = 2; i < N; ++i)
        fac[i] = mul(fac[i - 1], i);

    inv[N - 1] = binpow(fac[N - 1], MOD - 2);

    for (int i = N - 2; i >= 1; --i)
        inv[i] = mul(inv[i + 1], i + 1);
    
    auto C = [&](int n, int k) {
        return mul(fac[n], mul(inv[k], inv[n - k]));
    };

    int tt; std::cin >> tt;
    while (tt--) {
        int n, k; std::cin >> n >> k;

        std::string s; std::cin >> s;

        s = " " + s + " ";

        int cnt1 = 0, cnt0 = 0;
        for (int i = 1; i <= n; ++i)
            if (s[i] == '1')
                cnt1++;
            else if (s[i] == '0')
                cnt0++;

        auto Idx = [&](int i) {
            i = ((n - i) / (k - 1)) * (k - 1) + i;

            return n - i + 1;
        };

        bool flag = true;
        std::vector<int> val(k + 2, 2);
        int c0 = 0, c1 = 0;
        auto Add = [&](int i) {
            if (s[i] == '1') {
                cnt1--;

                int j = Idx(i);
                if (val[j] == 0)
                    flag = false;

                val[j] = 1;

                if (j != k)
                    c1++;
            } else if (s[i] == '0') {
                cnt0--;

                int j = Idx(i);
                if (val[j] == 1)
                    flag = false;

                val[j] = 0;

                if (j != k)
                    c0++;
            }
        };

        int res = 0;
        for (int i = n; i >= 1; --i) {
            if (!flag || c1 > k / 2 || c0 > k / 2)
                break;

            int cn1 = cnt1, cn0 = cnt0;

            if (s[i] == '1')
                cn1--;
            else if (s[i] == '0')
                cn0--;

            if ((cnt1 && cnt0 || i > n - k + 1 || cnt1 && val[Idx(i)] != 0 || cnt0 && val[Idx(i)] != 1 || (!cnt1 && !cnt0 && val[Idx(i)] != 2)) && i > 1) {
                Add(i);

                continue;
            }

            if (i == n - k + 1) {
                int c = i - (n - k + 1) + 1;

                if (!cnt0) {
                    c += c1;

                    if (c > k / 2) {
                        add_self(res, binpow(2, n - i - c1 - c0));
                    } else {
                        int vl = k / 2 + 1 - c;

                        assert(vl <= n - i - c1 - c0);

                        add_self(res, mul(C(n - i - c1 - c0, vl), binpow(2, n - i - c1 - c0 - vl)));
                    }

                    c -= c1;
                } else if (!cnt1) {
                    c += c0;

                    if (c > k / 2) {
                        add_self(res, binpow(2, n - i - c1 - c0));
                    } else {
                        int vl = k / 2 + 1 - c;

                        assert(vl <= n - i - c1 - c0);

                        add_self(res, mul(C(n - i - c1 - c0, vl), binpow(2, n - i - c1 - c0 - vl)));
                    }

                    c -= c0;
                }
            } else {
                add_self(res, C(k - c1 - c0 - 1, k / 2 - c1));

                if (!cnt0 && !cnt1)
                    add_self(res, C(k - c1 - c0 - 1, k / 2 - c1));

            }

            std::cout << res << '\n';

            Add(i);
        }

        std::cout << res << '\n';
    }

    return 0;
}
