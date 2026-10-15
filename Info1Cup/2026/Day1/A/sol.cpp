#include <bits/stdc++.h>

constexpr int N = 6e5;


std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
#define rnd(l, r) std::uniform_int_distribution<int>(l, r)(rng)

int P, MOD;

inline bool prime(int n) {
    if (n == 1) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

inline bool comp(std::string s, std::string t) {
    std::reverse(s.begin(), s.end());
    std::reverse(t.begin(), t.end());

    return s >= t;
}

inline const bool comb(std::string s, std::string t) {
    std::reverse(s.begin(), s.end());
    std::reverse(t.begin(), t.end());

    return s < t;
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline void add_self(int a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }

    if (a < 0) {
        a += MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    P = rnd(1e7, 1e8);
    MOD = rnd(1e8 + 1, 1e9);

    while (!prime(P)) {
        P++;
    }

    while (!prime(MOD)) {
        MOD++;
    }

    int n, q; std::cin >> n >> q;

    std::vector<std::string> a(n);
    std::vector<std::vector<int>> hsh(n);
    std::vector<int> pow_p(N, 1);
    for (int i = 1; i < N; ++i) {
        pow_p[i] = mul(pow_p[i - 1], P);
    }
    

    int64_t sum = 0;
    int mx = 0;
    for (auto &u: a) {
        std::cin >> u;

        std::reverse(u.begin(), u.end());
        mx = std::max(mx, (int)u.size());

        for (auto v: u) {
            sum += v - '0';
        }
    }

    std::vector<std::string> y(q);
    for (int i = 0; i < q; ++i) {
        std::cin >> y[i];
        mx = std::max(mx, (int)y[i].size());
    }

    std::vector<std::vector<int>> sr(mx);
    for (auto &u: a) {
        while (u.size() < mx) {
            u += "0";
        }

        for (int i = 0; i < mx; ++i) {
            if (i) {
                add_self(hsh[i], hsh[i - 1]); 
            }

            add_self(hsh[i], u[i] * pow_p[i]);
        }

        std::string t;
        for (int i = 0; i < mx; ++i) {
            t += u[i];

            sr[i].emplace_back(t);
        }
    }

    auto Get = [&](int i, int l, int r) {
        int res = hsh[i][r];

        add_self(res, -(l ? hsh[i][l - 1] : 0));

        res = mul(res, pow_p[N - l]);

        return res;
    };

    auto G1 = [&](auto &hs, int l, int r) {
    }

    for (int i = 0; i < mx; ++i) {
        std::sort(sr[i].begin(), sr[i].end(), [&](int k, int j) {
            int l = 0, r = i, ans = -1;

            while (l <= r) {
                int m = l + r >> 1;

                if (Get(k, m, i) == Get(j, m, i)) {
                    r = m - 1;
                } else {
                    l = m + 1, ans = m;
                }
            }

            if (ans != -1 || a[k][ans] < a[j][ans]) {
                return true;
            }
        });
    }


    for (int i = 0; i < q; ++i) {
        auto x = y[i];
        std::reverse(x.begin(), x.end());

        int sz = mx;
        while (x.size() < mx) {
            x += "0";
        }

        int64_t res = 0;
        for (auto u: x) {
            res += u - '0';
        }

        res *= n;
        res += sum;
        
        bool flag = false;
        std::string t;
        std::vector<int> hs;
        for (int i = 0; i < sz; ++i) {
            int val = 10 - x[i] + '0';

            val -= flag;

            val %= 10;

            if (!flag && x[i] != '0') {
                flag = true;
            }

            t += char(val + '0');
            hs.emplace_back(((hs.size() ? hs.back() : 0) + mul(t.back(), pow_p[t.size() - 1])) % MOD);

            if (flag) {
                int l = 0, r = (int)sr[i].size() - 1, ans = sr[i].size();
                while (l <= r) {
                    int m = l + r >> 1;

                    int idx = sr[i][m];
                    {
                        int l = 0, r = i, ans = -1;
                        while (l <= r) {
                            int m = l + r >> 1;

                            if (Get(idx, m, i) == ) {
                            }
                        }
                    }
                    if (comp(sr[i][m], t)) {
                        ans = m, r = m - 1;
                    } else {
                        l = m + 1;
                    }
                }

                res -= 9 * ((int)sr[i].size() - ans);
            }
        }

        std::cout << res << '\n';
    }
}
