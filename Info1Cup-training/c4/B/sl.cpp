/**
 *    author:  feev1x
 *    created: 31.01.2025 09:29:00
**/
#include <bits/stdc++.h>

constexpr int MOD = 1e9 + 7, N = 1e5 + 5;

int fact[N];

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int fac(int n) {
    if (n == 0) {
        return 1;
    }

    if (fact[n]) {
        return fact[n];
    }

    return fact[n] = mul(n, fac(n - 1));
}

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; std::cin >> n;

    std::string s; std::cin >> s;

    // 0 = 28, 1 = 29, 2 = 30, 3 = 31
    std::vector<std::array<int, 4>> cnt_r(n + 1, {0, 0, 0, 0});
    std::vector<int> cnt_l(n + 1);
    std::vector<std::array<int, 10>> cnt(n + 1, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0});

    for (int i = n - 1; i >= 0; --i) {
        cnt_r[i] = cnt_r[i + 1];
        for (int j = 0; j < 10; ++j) {
            if (cnt[i][j] != 0) {
                assert(false);
            }
        }
        cnt[i] = cnt[i + 1];

        if (s[i] == '/') {
            continue;
        }

        if (s[i] != '0') {

            for (int j = 0; j < 4; ++j) {
                add_self(cnt_r[i][j], 1);
            }
            
            if (s[i] == '3') {
                add_self(cnt_r[i][3], cnt[i][1]);
                add_self(cnt_r[i][3], cnt[i][0]);
                add_self(cnt_r[i][2], cnt[i][0]);
            } else if (s[i] == '2') {

                for (int j = 0; j < 10; ++j) {
                    add_self(cnt_r[i][3], cnt[i][j]);
                    add_self(cnt_r[i][2], cnt[i][j]);
                    add_self(cnt_r[i][1], cnt[i][j]);

                    if (j < 9) {
                        add_self(cnt_r[i][0], cnt[i][j]);
                    }
                }
            } else if (s[i] == '1') {

                for (int j = 0; j < 10; ++j) {
                    add_self(cnt_r[i][3], cnt[i][j]);
                    add_self(cnt_r[i][2], cnt[i][j]);
                    add_self(cnt_r[i][1], cnt[i][j]);
                    add_self(cnt_r[i][0], cnt[i][j]);
                }
            }
        }

        add_self(cnt[i][s[i] - '0'], 1);
    }

    for (int i = 0; i < n; ++i) {
        if (i) {
            cnt_l[i] = cnt_l[i - 1];
        }

        if (s[i] == '/') {
            continue;
        }

        cnt_l[i] = mul(cnt_l[i], 2);

        if (s[i] != '0') {
            add_self(cnt_l[i], 1);
        }
    }


    int res = 0, nw = 0, on = 0, one = 0, ls = -1, lsnw = 0, two = 0, zero = 0, full = 0;
    std::array<int, 4> cn{};
    for (int i = n - 1; i >= 0; --i) {
        if (ls == -1) {
            if (s[i] == '/') {
                ls = i;
                for (int j = 0; j < 4; ++j) {
                    add_self(cn[j], cnt_r[ls][j]);
                }
            }
        } else {
            if (s[i] == '/') {
                add_self(res, mul(full, cnt_l[i]));
                ls = i;
                for (int j = 0; j < 4; ++j) {
                    add_self(cn[j], cnt_r[ls][j]);
                }
                on = one = two = zero = 0;
                lsnw = nw;
            } else {
                if (s[i] == '1') {
                    add_self(nw, cn[2]);
                    add_self(one, 1);
                } else if (s[i] < '3') {
                    if (s[i] == '2') {
                        add_self(two, 1);
                    } else {
                        add_self(zero, 1);
                    }
                    add_self(nw, cn[3]);
                }

                if (s[i] != '0') {
                    if (s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '8') {
                        add_self(full, cn[3]);
                    } else {
                        add_self(full, cn[2]);
                    }

                    if (s[i] == '1') {
                        add_self(full, mul(two, cn[3]));
                        add_self(full, mul(zero, cn[3]));
                        add_self(full, mul(one - 1, cn[2]));
                        add_self(full, lsnw);
                    }
                }
            }
        }
    }

    std::cout << res << '\n';
    return 0;
}
