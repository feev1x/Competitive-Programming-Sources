/**
 *    author:  feev1x
 *    created: 09.01.2025 12:34:28
**/
#include <bits/stdc++.h>

using digitarray = std::array<std::array<std::array<int, 3>, 19>, 19>;

constexpr int MOD = 1e9 + 7;

inline void add_self(int &a, int b) {
    a += b;

    if (a >= MOD) {
        a -= MOD;
    }
}

inline void sub_self(int &a, int b) {
    a -= b;

    if (a < 0) {
        a += MOD;
    }
}

inline int mul(int a, int b) {
    return (int64_t)a * b % MOD;
}

inline int binpow(int a, int n) {
    int res = 1;

    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }

        a = mul(a, a);
        n >>= 1;
    }

    return res;
}

inline int divide(int a, int b) {
    return mul(a, binpow(b, MOD - 2));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n; int64_t A1, B1; std::cin >> n >> A1 >> B1; A1--;

    std::string sA = std::to_string(A1), sB = std::to_string(B1);

    std::vector<int> a(n + 1), A(1), B(1), fac(n + 1, 1);
    std::vector ans(n + 1, std::vector<int>(n + 1));
    digitarray dp{}, dp1{};
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        fac[i] = mul(fac[i - 1], i);
    }

    for (auto u: sA) {
        A.emplace_back(u - '0');
    }

    for (auto u: sB) {
        B.emplace_back(u - '0');
    }

    auto C = [&](int n, int k) {
        return divide(fac[n], mul(fac[n - k], fac[k]));
    };

    for (int l = 1; l <= n; ++l) {
        dp = dp1 = {};

        for (int r = l; r <= n; ++r) {
            auto Calc = [&](std::vector<int> s, digitarray &dp_calc) {
                int res = 0;

                digitarray dp_temp = dp_calc;
                for (int flag = 0; flag < 3; ++flag) {
                    for (int i = 1; i < s.size(); ++i) {
                        int val = s[i] == a[r] ? 1 : (s[i] > a[r] ? 0 : 2);

                        if (val == flag) {
                            add_self(dp_temp[i][i][flag], 2);
                        }

                        for (int j = i + 1; j < s.size(); ++j) {
                            for (int flag1 = 0; flag1 < 3; ++flag1) {
                                val = a[r] > s[i] ? 2 : a[r] == s[i] ? flag1 : 0;

                                if (val == flag) {
                                    add_self(dp_temp[i][j][flag], dp_calc[i + 1][j][flag1]);
                                }

                                val = flag1 == 1 ? (a[r] > s[j] ? 2 : a[r] == s[j] ? 1 : 0) : flag1; 
                                if (val == flag) {
                                    add_self(dp_temp[i][j][flag], dp_calc[i][j - 1][flag1]);
                                }
                            }
                        }
                    }
                }

                add_self(res, dp_temp[1][s.size() - 1][0]);
                add_self(res, dp_temp[1][s.size() - 1][1]);
                for (int i = 1; i + 1 < s.size() && i <= r - l + 1; ++i) {
                    add_self(res, mul(C(r - l + 1, i), 1 << i));
                }

                dp_calc = dp_temp;
                return res;
            };

            add_self(ans[l][r], Calc(B, dp1));
            sub_self(ans[l][r], Calc(A, dp));
        }
    }

    int q; std::cin >> q;
    while (q--) {
        int l, r; std::cin >> l >> r;
        
        std::cout << ans[l][r] << '\n';
    }
    return 0;
}
